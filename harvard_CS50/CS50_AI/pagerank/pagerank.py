import os
import random
import re
import sys

DAMPING = 0.85
SAMPLES = 10000


def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: python pagerank.py corpus")
    corpus = crawl(sys.argv[1])
    ranks = sample_pagerank(corpus, DAMPING, SAMPLES)
    print(f"PageRank Results from Sampling (n = {SAMPLES})")
    for page in sorted(ranks):
        print(f"  {page}: {ranks[page]:.4f}")
    ranks = iterate_pagerank(corpus, DAMPING)
    print(f"PageRank Results from Iteration")
    for page in sorted(ranks):
        print(f"  {page}: {ranks[page]:.4f}")


def crawl(directory):
    """
    Parse a directory of HTML pages and check for links to other pages.
    Return a dictionary where each key is a page, and values are
    a list of all other pages in the corpus that are linked to by the page.
    """
    pages = dict()

    # Extract all links from HTML files
    for filename in os.listdir(directory):
        if not filename.endswith(".html"):
            continue
        with open(os.path.join(directory, filename)) as f:
            contents = f.read()
            links = re.findall(r"<a\s+(?:[^>]*?)href=\"([^\"]*)\"", contents)
            pages[filename] = set(links) - {filename}

    # Only include links to other pages in the corpus
    for filename in pages:
        pages[filename] = set(
            link for link in pages[filename]
            if link in pages
        )

    return pages


def transition_model(corpus, page, damping_factor):
    """
    Return a probability distribution over which page to visit next,
    given a current page.

    With probability `damping_factor`, choose a link at random
    linked to by `page`. With probability `1 - damping_factor`, choose
    a link at random chosen from all pages in the corpus.
    """
    transition_dict = {}
    num_pages = len(corpus)
    num_page2link = len(corpus[page])
    if num_page2link == 0:
        for key in corpus.keys():
            transition_dict[key] = 1 / num_pages
    else:
        for key in corpus.keys():
            if key == page or key not in corpus[page]:
                transition_dict[key] = (1 - damping_factor) * 1 / num_pages
            else:
                transition_dict[key] = damping_factor * 1 / \
                    num_page2link + (1 - damping_factor) * 1 / num_pages
    return transition_dict


def sample_pagerank(corpus, damping_factor, n):
    """
    Return PageRank values for each page by sampling `n` pages
    according to transition model, starting with a page at random.

    Return a dictionary where keys are page names, and values are
    their estimated PageRank value (a value between 0 and 1). All
    PageRank values should sum to 1.
    """
    pagerank_dict = {page: 0 for page in corpus}
    cur_page = random.choice(list(corpus.keys()))
    pagerank_dict[cur_page] = 1
    for _ in range(n - 1):
        transition_dict = transition_model(corpus, cur_page, damping_factor)
        keys = list(transition_dict.keys())
        prob = list(transition_dict.values())
        cur_page = random.choices(keys, weights=prob, k=1)[0]
        pagerank_dict[cur_page] += 1
    for k, v in pagerank_dict.items():
        pagerank_dict[k] = v / n
    return pagerank_dict


def iterate_pagerank(corpus, damping_factor):
    """
    Return PageRank values for each page by iteratively updating
    PageRank values until convergence.

    Return a dictionary where keys are page names, and values are
    their estimated PageRank value (a value between 0 and 1). All
    PageRank values should sum to 1.
    """
    num_pages = len(corpus)
    pagerank = {page: 1 / num_pages for page in corpus.keys()}
    new_pagerank = {}

    # Iterate until convergence
    while True:
        for page in corpus:
            temp = 0
            for linking_page in corpus:
                if page in corpus[linking_page]:
                    temp += pagerank[linking_page] / len(corpus[linking_page])
                # if page has no links, interpret it as having one link for every other page
                elif len(corpus[linking_page]) == 0:
                    temp += pagerank[linking_page] / num_pages
            temp *= damping_factor
            temp += (1 - damping_factor) / num_pages
            new_pagerank[page] = temp

        difference = all([abs(new_pagerank[x] - pagerank[x]) < 0.001 for x in pagerank])
        if difference:
            break
        else:
            pagerank = new_pagerank.copy()

    return pagerank


if __name__ == "__main__":
    main()
