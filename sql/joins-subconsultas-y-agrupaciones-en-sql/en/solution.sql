SELECT p.name AS programme,
       m.name AS module,
       COUNT(*) AS enrolled,
       COUNT(e.mark) AS sat,
       ROUND(AVG(e.mark), 2) AS avg_mark,
       ROUND(pa.prog_avg, 2) AS programme_avg
FROM modules m
JOIN programmes p ON p.id = m.programme_id
JOIN enrolments e ON e.module_id = m.id
JOIN (SELECT m2.programme_id AS prog_id,
             AVG(e2.mark) AS prog_avg
      FROM modules m2
      JOIN enrolments e2 ON e2.module_id = m2.id
      GROUP BY m2.programme_id) pa ON pa.prog_id = m.programme_id
GROUP BY m.id, m.name, p.name, pa.prog_avg
HAVING AVG(e.mark) < pa.prog_avg
ORDER BY p.name, AVG(e.mark), m.name;
