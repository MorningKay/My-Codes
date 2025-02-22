CREATE TABLE IF NOT EXISTS "score" (
    course VARCHAR(50),
    credit INTEGER,
    grades REAL,
    GPA REAL
);

INSERT INTO "score" (course, credit, grades, GPA)
VALUES
    ('English', 3, 91.0, 273),
    ('Calculus(A)', 6, 100.0, 600),
    ('Intro to Applied Chemistry', 1, 89.0, 89);

-- INSERT INTO "score" (course, credit, grades, GPA)
-- VALUES
--     ('信息技术与计算思维导论', 2, 92.0, 184),
--     ('羽毛球', 1, 87.0, 87),
--     ('军事技能', 2, 94.0, 188);

