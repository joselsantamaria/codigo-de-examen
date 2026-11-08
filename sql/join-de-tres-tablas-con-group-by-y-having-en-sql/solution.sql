SELECT b.nombre               AS barrio,
       COUNT(DISTINCT h.id)   AS hortelanos,
       COUNT(*)               AS cosechas,
       SUM(c.kg)              AS kg_total
FROM barrio AS b
JOIN hortelano AS h ON h.barrio_id = b.id
JOIN cosecha   AS c ON c.hortelano_id = h.id
WHERE c.fecha >= '2024-01-01'
  AND c.fecha <  '2025-01-01'
GROUP BY b.id, b.nombre
HAVING COUNT(DISTINCT h.id) >= 2
   AND SUM(c.kg) >= 20
ORDER BY kg_total DESC, barrio ASC;
