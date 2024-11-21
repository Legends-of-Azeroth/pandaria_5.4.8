-- Ancient Teleport: Dalaran
-- https://www.wowhead.com/spell=120145/ancient-teleport-dalaran
-- https://www.wowhead.com/spell=221237/ancient-portal-dalaran (legion)
-- https://www.wowhead.com/spell=121848/ancient-portal-dalaran (pandria)
DELETE FROM `spell_target_position` WHERE (`id`,`effIndex`) IN ((120145,0),(121848,0));
INSERT INTO `spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(120145, 0, 0, 303.22, 347.21, 125.53, 1.721941947937011718),
(121848, 0, 0, 303.22, 347.21, 125.53, 1.721941947937011718);

-- Update wrong name and spellid of ancient-portal-dalaran
UPDATE `gameobject_template` SET `name`='Portal to Dalaran',`data0`=121848 WHERE `entry`=211835;
