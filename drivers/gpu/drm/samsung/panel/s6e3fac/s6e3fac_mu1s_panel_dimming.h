/*
 * linux/drivers/video/fbdev/exynos/panel/s6e3fac/s6e3fac_mu1s_panel_dimming.h
 *
 * Header file for S6E3FAC Dimming Driver
 *
 * Copyright (c) 2016 Samsung Electronics
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __S6E3FAC_MU1S_PANEL_DIMMING_H___
#define __S6E3FAC_MU1S_PANEL_DIMMING_H___
#include "../dimming.h"
#include "../panel_dimming.h"
#include "s6e3fac_dimming.h"

/*
 * PANEL INFORMATION
 * LDI : S6E3FAC
 * PANEL : MU1S
 */

static unsigned int mu1s_brt_tbl[S6E3FAC_MU1S_TOTAL_STEP] = {
	BRT(0), BRT(1), BRT(2), BRT(3), BRT(4), BRT(5), BRT(6), BRT(7), BRT(8), BRT(9), BRT(10),
	BRT(11), BRT(12), BRT(13), BRT(14), BRT(15), BRT(16), BRT(17), BRT(18), BRT(19), BRT(20),
	BRT(21), BRT(22), BRT(23), BRT(24), BRT(25), BRT(26), BRT(27), BRT(28), BRT(29), BRT(30),
	BRT(31), BRT(32), BRT(33), BRT(34), BRT(35), BRT(36), BRT(37), BRT(38), BRT(39), BRT(40),
	BRT(41), BRT(42), BRT(43), BRT(44), BRT(45), BRT(46), BRT(47), BRT(48), BRT(49), BRT(50),
	BRT(51), BRT(52), BRT(53), BRT(54), BRT(55), BRT(56), BRT(57), BRT(58), BRT(59), BRT(60),
	BRT(61), BRT(62), BRT(63), BRT(64), BRT(65), BRT(66), BRT(67), BRT(68), BRT(69), BRT(70),
	BRT(71), BRT(72), BRT(73), BRT(74), BRT(75), BRT(76), BRT(77), BRT(78), BRT(79), BRT(80),
	BRT(81), BRT(82), BRT(83), BRT(84), BRT(85), BRT(86), BRT(87), BRT(88), BRT(89), BRT(90),
	BRT(91), BRT(92), BRT(93), BRT(94), BRT(95), BRT(96), BRT(97), BRT(98), BRT(99), BRT(100),
	BRT(101), BRT(102), BRT(103), BRT(104), BRT(105), BRT(106), BRT(107), BRT(108), BRT(109), BRT(110),
	BRT(111), BRT(112), BRT(113), BRT(114), BRT(115), BRT(116), BRT(117), BRT(118), BRT(119), BRT(120),
	BRT(121), BRT(122), BRT(123), BRT(124), BRT(125), BRT(126), BRT(127), BRT(128), BRT(129), BRT(130),
	BRT(131), BRT(132), BRT(133), BRT(134), BRT(135), BRT(136), BRT(137), BRT(138), BRT(139), BRT(140),
	BRT(141), BRT(142), BRT(143), BRT(144), BRT(145), BRT(146), BRT(147), BRT(148), BRT(149), BRT(150),
	BRT(151), BRT(152), BRT(153), BRT(154), BRT(155), BRT(156), BRT(157), BRT(158), BRT(159), BRT(160),
	BRT(161), BRT(162), BRT(163), BRT(164), BRT(165), BRT(166), BRT(167), BRT(168), BRT(169), BRT(170),
	BRT(171), BRT(172), BRT(173), BRT(174), BRT(175), BRT(176), BRT(177), BRT(178), BRT(179), BRT(180),
	BRT(181), BRT(182), BRT(183), BRT(184), BRT(185), BRT(186), BRT(187), BRT(188), BRT(189), BRT(190),
	BRT(191), BRT(192), BRT(193), BRT(194), BRT(195), BRT(196), BRT(197), BRT(198), BRT(199), BRT(200),
	BRT(201), BRT(202), BRT(203), BRT(204), BRT(205), BRT(206), BRT(207), BRT(208), BRT(209), BRT(210),
	BRT(211), BRT(212), BRT(213), BRT(214), BRT(215), BRT(216), BRT(217), BRT(218), BRT(219), BRT(220),
	BRT(221), BRT(222), BRT(223), BRT(224), BRT(225), BRT(226), BRT(227), BRT(228), BRT(229), BRT(230),
	BRT(231), BRT(232), BRT(233), BRT(234), BRT(235), BRT(236), BRT(237), BRT(238), BRT(239), BRT(240),
	BRT(241), BRT(242), BRT(243), BRT(244), BRT(245), BRT(246), BRT(247), BRT(248), BRT(249), BRT(250),
	BRT(251), BRT(252), BRT(253), BRT(254), BRT(255),
	BRT(256), BRT(257), BRT(258), BRT(259), BRT(260), BRT(261), BRT(262), BRT(263), BRT(264), BRT(265),
	BRT(266), BRT(267), BRT(268), BRT(269), BRT(270), BRT(271), BRT(272), BRT(273), BRT(274), BRT(275),
	BRT(276), BRT(277), BRT(278), BRT(279), BRT(280), BRT(281), BRT(282), BRT(283), BRT(284), BRT(285),
	BRT(286), BRT(287), BRT(288), BRT(289), BRT(290), BRT(291), BRT(292), BRT(293), BRT(294), BRT(295),
	BRT(296), BRT(297), BRT(298), BRT(299), BRT(300), BRT(301), BRT(302), BRT(303), BRT(304), BRT(305),
	BRT(306), BRT(307), BRT(308), BRT(309), BRT(310), BRT(311), BRT(312), BRT(313), BRT(314), BRT(315),
	BRT(316), BRT(317), BRT(318), BRT(319), BRT(320), BRT(321), BRT(322), BRT(323), BRT(324), BRT(325),
	BRT(326), BRT(327), BRT(328), BRT(329), BRT(330), BRT(331), BRT(332), BRT(333), BRT(334), BRT(335),
	BRT(336), BRT(337), BRT(338), BRT(339), BRT(340), BRT(341), BRT(342), BRT(343), BRT(344), BRT(345),
	BRT(346), BRT(347), BRT(348), BRT(349), BRT(350), BRT(351), BRT(352), BRT(353), BRT(354), BRT(355),
	BRT(356), BRT(357), BRT(358), BRT(359), BRT(360), BRT(361), BRT(362), BRT(363), BRT(364), BRT(365),
	BRT(366), BRT(367), BRT(368), BRT(369), BRT(370), BRT(371), BRT(372), BRT(373), BRT(374), BRT(375),
	BRT(376), BRT(377), BRT(378), BRT(379), BRT(380), BRT(381), BRT(382), BRT(383), BRT(384), BRT(385),
	BRT(386), BRT(387), BRT(388), BRT(389), BRT(390), BRT(391), BRT(392), BRT(393), BRT(394), BRT(395),
	BRT(396), BRT(397), BRT(398), BRT(399), BRT(400), BRT(401), BRT(402), BRT(403), BRT(404), BRT(405),
	BRT(406), BRT(407), BRT(408), BRT(409), BRT(410), BRT(411), BRT(412), BRT(413), BRT(414), BRT(415),
	BRT(416), BRT(417), BRT(418), BRT(419), BRT(420), BRT(421), BRT(422), BRT(423), BRT(424), BRT(425),
	BRT(426), BRT(427), BRT(428), BRT(429), BRT(430), BRT(431), BRT(432), BRT(433), BRT(434), BRT(435),
	BRT(436), BRT(437), BRT(438), BRT(439), BRT(440), BRT(441), BRT(442), BRT(443), BRT(444), BRT(445),
	BRT(446), BRT(447), BRT(448), BRT(449), BRT(450), BRT(451), BRT(452), BRT(453), BRT(454), BRT(455),
	BRT(456), BRT(457), BRT(458), BRT(459), BRT(460), BRT(461), BRT(462), BRT(463), BRT(464), BRT(465),
	BRT(466), BRT(467), BRT(468), BRT(469), BRT(470), BRT(471), BRT(472), BRT(473), BRT(474), BRT(475),
	BRT(476), BRT(477), BRT(478), BRT(479), BRT(480), BRT(481), BRT(482), BRT(483), BRT(484), BRT(485),
	BRT(486), BRT(487), BRT(488), BRT(489), BRT(490), BRT(491), BRT(492), BRT(493), BRT(494), BRT(495),
	BRT(496), BRT(497), BRT(498), BRT(499), BRT(500), BRT(501), BRT(502), BRT(503), BRT(504), BRT(505),
	BRT(506), BRT(507), BRT(508), BRT(509), BRT(510), BRT(511), BRT(512), BRT(513), BRT(514), BRT(515),
	BRT(516), BRT(517), BRT(518), BRT(519), BRT(520), BRT(521), BRT(522), BRT(523), BRT(524), BRT(525),
	BRT(526), BRT(527), BRT(528), BRT(529), BRT(530), BRT(531), BRT(532), BRT(533), BRT(534), BRT(535),
	BRT(536), BRT(537), BRT(538), BRT(539), BRT(540), BRT(541), BRT(542), BRT(543), BRT(544), BRT(545),
	BRT(546), BRT(547), BRT(548), BRT(549), BRT(550), BRT(551), BRT(552), BRT(553), BRT(554), BRT(555),
	BRT(556), BRT(557), BRT(558), BRT(559), BRT(560), BRT(561), BRT(562), BRT(563), BRT(564), BRT(565),
	BRT(566), BRT(567), BRT(568), BRT(569), BRT(570), BRT(571), BRT(572), BRT(573), BRT(574), BRT(575),
	BRT(576), BRT(577), BRT(578), BRT(579), BRT(580), BRT(581), BRT(582), BRT(583), BRT(584), BRT(585),
	BRT(586), BRT(587), BRT(588), BRT(589), BRT(590), BRT(591), BRT(592), BRT(593), BRT(594), BRT(595),
	BRT(596), BRT(597), BRT(598), BRT(599), BRT(600), BRT(601), BRT(602), BRT(603), BRT(604), BRT(605),
	BRT(606), BRT(607), BRT(608), BRT(609), BRT(610), BRT(611), BRT(612), BRT(613), BRT(614), BRT(615),
	BRT(616), BRT(617), BRT(618), BRT(619), BRT(620), BRT(621), BRT(622), BRT(623), BRT(624), BRT(625),
	BRT(626), BRT(627), BRT(628), BRT(629), BRT(630), BRT(631), BRT(632), BRT(633), BRT(634), BRT(635),
	BRT(636), BRT(637), BRT(638), BRT(639), BRT(640), BRT(641), BRT(642), BRT(643), BRT(644), BRT(645),
	BRT(646), BRT(647), BRT(648), BRT(649), BRT(650), BRT(651), BRT(652), BRT(653), BRT(654), BRT(655),
	BRT(656), BRT(657), BRT(658), BRT(659), BRT(660), BRT(661), BRT(662), BRT(663), BRT(664), BRT(665),
	BRT(666), BRT(667), BRT(668), BRT(669), BRT(670), BRT(671), BRT(672), BRT(673), BRT(674), BRT(675),
	BRT(676), BRT(677), BRT(678), BRT(679), BRT(680), BRT(681), BRT(682), BRT(683), BRT(684), BRT(685),
	BRT(686), BRT(687), BRT(688), BRT(689), BRT(690), BRT(691), BRT(692), BRT(693), BRT(694), BRT(695),
	BRT(696), BRT(697), BRT(698), BRT(699), BRT(700), BRT(701), BRT(702), BRT(703), BRT(704), BRT(705),
	BRT(706), BRT(707), BRT(708), BRT(709), BRT(710), BRT(711), BRT(712), BRT(713), BRT(714), BRT(715),
	BRT(716), BRT(717), BRT(718), BRT(719), BRT(720), BRT(721), BRT(722), BRT(723), BRT(724), BRT(725),
	BRT(726), BRT(727), BRT(728), BRT(729), BRT(730), BRT(731), BRT(732), BRT(733), BRT(734), BRT(735),
	BRT(736), BRT(737), BRT(738), BRT(739), BRT(740), BRT(741), BRT(742), BRT(743), BRT(744), BRT(745),
	BRT(746), BRT(747), BRT(748), BRT(749), BRT(750), BRT(751), BRT(752), BRT(753), BRT(754), BRT(755),
	BRT(756), BRT(757), BRT(758), BRT(759), BRT(760), BRT(761), BRT(762), BRT(763), BRT(764), BRT(765),
	BRT(766), BRT(767), BRT(768), BRT(769), BRT(770), BRT(771), BRT(772), BRT(773), BRT(774), BRT(775),
	BRT(776), BRT(777), BRT(778), BRT(779), BRT(780), BRT(781), BRT(782), BRT(783), BRT(784), BRT(785),
	BRT(786), BRT(787), BRT(788), BRT(789), BRT(790), BRT(791), BRT(792), BRT(793), BRT(794), BRT(795),
	BRT(796), BRT(797), BRT(798), BRT(799), BRT(800), BRT(801), BRT(802), BRT(803), BRT(804), BRT(805),
	BRT(806), BRT(807), BRT(808), BRT(809), BRT(810), BRT(811), BRT(812), BRT(813), BRT(814), BRT(815),
	BRT(816), BRT(817), BRT(818), BRT(819), BRT(820), BRT(821), BRT(822), BRT(823), BRT(824), BRT(825),
	BRT(826), BRT(827), BRT(828), BRT(829), BRT(830), BRT(831), BRT(832), BRT(833), BRT(834), BRT(835),
	BRT(836), BRT(837), BRT(838), BRT(839), BRT(840), BRT(841), BRT(842), BRT(843), BRT(844), BRT(845),
	BRT(846), BRT(847), BRT(848), BRT(849), BRT(850), BRT(851), BRT(852), BRT(853), BRT(854), BRT(855),
	BRT(856), BRT(857), BRT(858), BRT(859), BRT(860), BRT(861), BRT(862), BRT(863), BRT(864), BRT(865),
	BRT(866), BRT(867), BRT(868), BRT(869), BRT(870), BRT(871), BRT(872), BRT(873), BRT(874), BRT(875),
	BRT(876), BRT(877), BRT(878), BRT(879), BRT(880), BRT(881), BRT(882), BRT(883), BRT(884), BRT(885),
	BRT(886), BRT(887), BRT(888), BRT(889), BRT(890), BRT(891), BRT(892), BRT(893), BRT(894), BRT(895),
	BRT(896), BRT(897), BRT(898), BRT(899), BRT(900), BRT(901), BRT(902), BRT(903), BRT(904), BRT(905),
	BRT(906), BRT(907), BRT(908), BRT(909), BRT(910), BRT(911), BRT(912), BRT(913), BRT(914), BRT(915),
	BRT(916), BRT(917), BRT(918), BRT(919), BRT(920), BRT(921), BRT(922), BRT(923), BRT(924), BRT(925),
	BRT(926), BRT(927), BRT(928), BRT(929), BRT(930), BRT(931), BRT(932), BRT(933), BRT(934), BRT(935),
	BRT(936), BRT(937), BRT(938), BRT(939), BRT(940), BRT(941), BRT(942), BRT(943), BRT(944), BRT(945),
	BRT(946), BRT(947), BRT(948), BRT(949), BRT(950), BRT(951), BRT(952), BRT(953), BRT(954), BRT(955),
	BRT(956), BRT(957), BRT(958), BRT(959), BRT(960), BRT(961), BRT(962), BRT(963), BRT(964), BRT(965),
	BRT(966), BRT(967), BRT(968), BRT(969), BRT(970), BRT(971), BRT(972), BRT(973), BRT(974), BRT(975),
	BRT(976), BRT(977), BRT(978), BRT(979), BRT(980), BRT(981), BRT(982), BRT(983), BRT(984), BRT(985),
	BRT(986), BRT(987), BRT(988), BRT(989), BRT(990), BRT(991), BRT(992), BRT(993), BRT(994), BRT(995),
	BRT(996), BRT(997), BRT(998), BRT(999), BRT(1000), BRT(1001), BRT(1002), BRT(1003), BRT(1004), BRT(1005),
	BRT(1006), BRT(1007), BRT(1008), BRT(1009), BRT(1010), BRT(1011), BRT(1012), BRT(1013), BRT(1014), BRT(1015),
	BRT(1016), BRT(1017), BRT(1018), BRT(1019), BRT(1020), BRT(1021), BRT(1022), BRT(1023), BRT(1024), BRT(1025),
	BRT(1026), BRT(1027), BRT(1028), BRT(1029), BRT(1030), BRT(1031), BRT(1032), BRT(1033), BRT(1034), BRT(1035),
	BRT(1036), BRT(1037), BRT(1038), BRT(1039), BRT(1040), BRT(1041), BRT(1042), BRT(1043), BRT(1044), BRT(1045),
	BRT(1046), BRT(1047), BRT(1048), BRT(1049), BRT(1050), BRT(1051), BRT(1052), BRT(1053), BRT(1054), BRT(1055),
	BRT(1056), BRT(1057), BRT(1058), BRT(1059), BRT(1060), BRT(1061), BRT(1062), BRT(1063), BRT(1064), BRT(1065),
	BRT(1066), BRT(1067), BRT(1068), BRT(1069), BRT(1070), BRT(1071), BRT(1072), BRT(1073), BRT(1074), BRT(1075),
	BRT(1076), BRT(1077), BRT(1078), BRT(1079), BRT(1080), BRT(1081), BRT(1082), BRT(1083), BRT(1084), BRT(1085),
	BRT(1086), BRT(1087), BRT(1088), BRT(1089), BRT(1090), BRT(1091), BRT(1092), BRT(1093), BRT(1094), BRT(1095),
	BRT(1096), BRT(1097), BRT(1098), BRT(1099), BRT(1100), BRT(1101), BRT(1102), BRT(1103), BRT(1104), BRT(1105),
	BRT(1106), BRT(1107), BRT(1108), BRT(1109), BRT(1110), BRT(1111), BRT(1112), BRT(1113), BRT(1114), BRT(1115),
	BRT(1116), BRT(1117), BRT(1118), BRT(1119), BRT(1120), BRT(1121), BRT(1122), BRT(1123), BRT(1124), BRT(1125),
	BRT(1126), BRT(1127), BRT(1128), BRT(1129), BRT(1130), BRT(1131), BRT(1132), BRT(1133), BRT(1134), BRT(1135),
	BRT(1136), BRT(1137), BRT(1138), BRT(1139), BRT(1140), BRT(1141), BRT(1142), BRT(1143), BRT(1144), BRT(1145),
	BRT(1146), BRT(1147), BRT(1148), BRT(1149), BRT(1150), BRT(1151), BRT(1152), BRT(1153), BRT(1154), BRT(1155),
	BRT(1156), BRT(1157), BRT(1158), BRT(1159), BRT(1160), BRT(1161), BRT(1162), BRT(1163), BRT(1164), BRT(1165),
	BRT(1166), BRT(1167), BRT(1168), BRT(1169), BRT(1170), BRT(1171), BRT(1172), BRT(1173), BRT(1174), BRT(1175),
	BRT(1176), BRT(1177), BRT(1178), BRT(1179), BRT(1180), BRT(1181), BRT(1182), BRT(1183), BRT(1184), BRT(1185),
	BRT(1186), BRT(1187), BRT(1188), BRT(1189), BRT(1190), BRT(1191), BRT(1192), BRT(1193), BRT(1194), BRT(1195),
	BRT(1196), BRT(1197), BRT(1198), BRT(1199), BRT(1200), BRT(1201), BRT(1202), BRT(1203), BRT(1204), BRT(1205),
	BRT(1206), BRT(1207), BRT(1208), BRT(1209), BRT(1210), BRT(1211), BRT(1212), BRT(1213), BRT(1214), BRT(1215),
	BRT(1216), BRT(1217), BRT(1218), BRT(1219), BRT(1220), BRT(1221), BRT(1222), BRT(1223), BRT(1224), BRT(1225),
	BRT(1226), BRT(1227), BRT(1228), BRT(1229), BRT(1230), BRT(1231), BRT(1232), BRT(1233), BRT(1234), BRT(1235),
	BRT(1236), BRT(1237), BRT(1238), BRT(1239), BRT(1240), BRT(1241), BRT(1242), BRT(1243), BRT(1244), BRT(1245),
	BRT(1246), BRT(1247), BRT(1248), BRT(1249), BRT(1250), BRT(1251), BRT(1252), BRT(1253), BRT(1254), BRT(1255),
	BRT(1256), BRT(1257), BRT(1258), BRT(1259), BRT(1260), BRT(1261), BRT(1262), BRT(1263), BRT(1264), BRT(1265),
	BRT(1266), BRT(1267), BRT(1268), BRT(1269), BRT(1270), BRT(1271), BRT(1272), BRT(1273), BRT(1274), BRT(1275),
};

static unsigned int mu1s_lum_tbl[S6E3FAC_MU1S_TOTAL_NR_LUMINANCE] = {
	/* normal 8x32 */
	1, 1, 2, 3, 3, 4, 5, 6,
	7, 7, 8, 9, 10, 11, 12, 14,
	15, 16, 17, 18, 19, 20, 22, 23,
	24, 25, 27, 28, 29, 31, 32, 33,
	35, 36, 37, 39, 40, 42, 43, 44,
	46, 47, 49, 50, 52, 53, 55, 56,
	58, 59, 61, 63, 64, 66, 67, 69,
	71, 72, 74, 75, 77, 79, 80, 82,
	84, 85, 87, 89, 91, 92, 94, 96,
	97, 99, 101, 103, 104, 106, 108, 110,
	112, 113, 115, 117, 119, 121, 122, 124,
	126, 128, 130, 132, 134, 135, 137, 139,
	141, 143, 145, 147, 149, 151, 153, 155,
	157, 158, 160, 162, 164, 166, 168, 170,
	172, 174, 176, 178, 180, 182, 184, 186,
	188, 190, 192, 194, 196, 199, 201, 203,
	205, 207, 209, 211, 213, 215, 217, 219,
	221, 224, 226, 228, 230, 232, 234, 236,
	238, 241, 243, 245, 247, 249, 251, 254,
	256, 258, 260, 262, 264, 267, 269, 271,
	273, 275, 278, 280, 282, 284, 287, 289,
	291, 293, 296, 298, 300, 302, 305, 307,
	309, 311, 314, 316, 318, 321, 323, 325,
	327, 330, 332, 334, 337, 339, 341, 344,
	346, 348, 351, 353, 355, 358, 360, 362,
	365, 367, 370, 372, 374, 377, 379, 382,
	384, 386, 389, 391, 393, 396, 398, 401,
	403, 406, 408, 410, 413, 415, 418, 420,
	423, 425, 428, 430, 432, 435, 437, 440,
	442, 445, 447, 450, 452, 455, 457, 460,
	462, 465, 467, 470, 472, 475, 477, 480,
	482, 485, 487, 490, 492, 495, 497, 500,
	/* hbm 8x127+4 */
	502, 504, 506, 508, 510, 512, 514, 516,
	518, 520, 522, 524, 525, 527, 529, 531,
	533, 535, 537, 539, 541, 543, 545, 547,
	549, 551, 553, 555, 557, 559, 561, 563,
	565, 567, 569, 571, 573, 575, 576, 578,
	580, 582, 584, 586, 588, 590, 592, 594,
	596, 598, 600, 602, 604, 606, 608, 610,
	612, 614, 616, 618, 620, 622, 624, 625,
	627, 629, 631, 633, 635, 637, 639, 641,
	643, 645, 647, 649, 651, 653, 655, 657,
	659, 661, 663, 665, 667, 669, 671, 673,
	675, 676, 678, 680, 682, 684, 686, 688,
	690, 692, 694, 696, 698, 700, 702, 704,
	706, 708, 710, 712, 714, 716, 718, 720,
	722, 724, 725, 727, 729, 731, 733, 735,
	737, 739, 741, 743, 745, 747, 749, 751,
	753, 755, 757, 759, 761, 763, 765, 767,
	769, 771, 773, 775, 776, 778, 780, 782,
	784, 786, 788, 790, 792, 794, 796, 798,
	800, 802, 804, 806, 808, 810, 812, 814,
	816, 818, 820, 822, 824, 825, 827, 829,
	831, 833, 835, 837, 839, 841, 843, 845,
	847, 849, 851, 853, 855, 857, 859, 861,
	863, 865, 867, 869, 871, 873, 875, 876,
	878, 880, 882, 884, 886, 888, 890, 892,
	894, 896, 898, 900, 902, 904, 906, 908,
	910, 912, 914, 916, 918, 920, 922, 924,
	925, 927, 929, 931, 933, 935, 937, 939,
	941, 943, 945, 947, 949, 951, 953, 955,
	957, 959, 961, 963, 965, 967, 969, 971,
	973, 975, 976, 978, 980, 982, 984, 986,
	988, 990, 992, 994, 996, 998, 1000, 1002,
	1004, 1006, 1008, 1010, 1012, 1014, 1016, 1018,
	1020, 1022, 1024, 1025, 1027, 1029, 1031, 1033,
	1035, 1037, 1039, 1041, 1043, 1045, 1047, 1049,
	1051, 1053, 1055, 1057, 1059, 1061, 1063, 1065,
	1067, 1069, 1071, 1073, 1075, 1076, 1078, 1080,
	1082, 1084, 1086, 1088, 1090, 1092, 1094, 1096,
	1098, 1100, 1102, 1104, 1106, 1108, 1110, 1112,
	1114, 1116, 1118, 1120, 1122, 1124, 1125, 1127,
	1129, 1131, 1133, 1135, 1137, 1139, 1141, 1143,
	1145, 1147, 1149, 1151, 1153, 1155, 1157, 1159,
	1161, 1163, 1165, 1167, 1169, 1171, 1173, 1175,
	1176, 1178, 1180, 1182, 1184, 1186, 1188, 1190,
	1192, 1194, 1196, 1198, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
	1200, 1200, 1200, 1200
};

static unsigned int mu1s_step_cnt_tbl[S6E3FAC_MU1S_TOTAL_STEP] = {
	[0 ... S6E3FAC_MU1S_TOTAL_STEP - 1] = 1,
};

static s32 mu1s_ctbl_60hs_48hs_le_255[S6E3FAC_NR_TP*3] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -24, -68, -24, -12, -35, -12, -8, -20, -5, -1, -4, 0, 0, -1, 0, 0, 0, 0, 7, 7, 8 };
static s32 mu1s_ctbl_60hs_48hs_gte_255[S6E3FAC_NR_TP*3] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -13, -45, -13, -5, -20, -6, -6, -13, -5, 0, -2, 0, 0, 0, 0, 0, 0, 0, 9, 9, 10 };

static struct dimming_color_offset mu1s_analog_gamma_offset[S6E3FAC_ANALOG_GAMMA_WRITE_SET_COUNT] = {
	[S6E3FAC_ANALOG_GAMMA_WRITE_SET_2] = GM2_LUT_V0_INIT(mu1s_ctbl_60hs_48hs_le_255),
	[S6E3FAC_ANALOG_GAMMA_WRITE_SET_3] = GM2_LUT_V0_INIT(mu1s_ctbl_60hs_48hs_gte_255),
};

struct brightness_table s6e3fac_mu1s_panel_brightness_table = {
	.control_type = BRIGHTNESS_CONTROL_TYPE_GAMMA_MODE2,
	.brt = mu1s_brt_tbl,
	.sz_brt = ARRAY_SIZE(mu1s_brt_tbl),
	.sz_ui_brt = S6E3FAC_MU1S_NR_STEP,
	.sz_hbm_brt = S6E3FAC_MU1S_HBM_STEP,
	.lum = mu1s_lum_tbl,
	.sz_lum = S6E3FAC_MU1S_TOTAL_NR_LUMINANCE,
	.sz_ui_lum = S6E3FAC_MU1S_NR_LUMINANCE,
	.sz_hbm_lum = S6E3FAC_MU1S_NR_HBM_LUMINANCE,
	.sz_ext_hbm_lum = 0,
	.brt_to_step = NULL,
	.sz_brt_to_step = 0,
	.step_cnt = mu1s_step_cnt_tbl,
	.sz_step_cnt = ARRAY_SIZE(mu1s_step_cnt_tbl),
	.vtotal = 3232,
};

static struct panel_dimming_info s6e3fac_mu1s_panel_dimming_info = {
	.name = "s6e3fac_mu1s",
	.dim_init_info = {
		NULL,
	},
	.target_luminance = -1,
	.nr_luminance = 0,
	.hbm_target_luminance = -1,
	.nr_hbm_luminance = 0,
	.extend_hbm_target_luminance = -1,
	.nr_extend_hbm_luminance = 0,
	.brt_tbl = &s6e3fac_mu1s_panel_brightness_table,
	/* dimming parameters */
	.dimming_maptbl = NULL,
	.dim_flash_on = false,
	.hbm_aor = NULL,
	.dimming_data = (void *)mu1s_analog_gamma_offset,
	.nr_dimming_data = ARRAY_SIZE(mu1s_analog_gamma_offset),
};
#endif /* __S6E3FAC_MU1S_PANEL_DIMMING_H___ */
