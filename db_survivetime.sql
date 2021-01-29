-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 29, 2021 at 02:06 AM
-- Server version: 10.4.13-MariaDB
-- PHP Version: 7.2.32

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `db_survivetime`
--

-- --------------------------------------------------------

--
-- Table structure for table `accounts`
--

CREATE TABLE `accounts` (
  `account_id` int(11) NOT NULL,
  `account_name` varchar(25) NOT NULL DEFAULT 'none',
  `account_password` varchar(64) NOT NULL DEFAULT 'none'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `accounts`
--

INSERT INTO `accounts` (`account_id`, `account_name`, `account_password`) VALUES
(1, 'EmmettHH', 'testetste'),
(2, 'Emmett', 'pass'),
(3, 'Emmettzzzz', 'testesdfdsff'),
(4, 'Emmettzzzzzzz', 'pass'),
(5, 'testttt', 'qrcina'),
(6, 'testtttzzz', 'pass'),
(7, 'Emet_vajt', 'fdsfdfsdfsd'),
(8, 'Emet_vajttt', 'pass');

-- --------------------------------------------------------

--
-- Table structure for table `banned`
--

CREATE TABLE `banned` (
  `banned_player` varchar(25) NOT NULL DEFAULT 'none',
  `banned_admin` varchar(25) NOT NULL DEFAULT 'none',
  `banned_reason` varchar(64) NOT NULL DEFAULT 'none'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `characters`
--

CREATE TABLE `characters` (
  `char_id` int(11) NOT NULL,
  `char_name` varchar(25) NOT NULL DEFAULT 'none',
  `char_score` smallint(6) NOT NULL DEFAULT 1,
  `char_money` mediumint(9) NOT NULL DEFAULT 10000,
  `char_skin` smallint(6) NOT NULL DEFAULT 26,
  `char_admin` smallint(6) NOT NULL DEFAULT 0,
  `char_admincode` mediumint(9) NOT NULL DEFAULT 0,
  `char_warn` smallint(6) NOT NULL DEFAULT 0,
  `char_warnreason` varchar(64) NOT NULL DEFAULT 'none',
  `char_muted` int(11) NOT NULL DEFAULT 0,
  `char_mutedmins` int(11) NOT NULL DEFAULT 0,
  `char_drugs` int(11) NOT NULL DEFAULT 0,
  `char_job` smallint(6) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `characters`
--

INSERT INTO `characters` (`char_id`, `char_name`, `char_score`, `char_money`, `char_skin`, `char_admin`, `char_admincode`, `char_warn`, `char_warnreason`, `char_muted`, `char_mutedmins`, `char_drugs`, `char_job`) VALUES
(1, 'EmmettHH', 1, 100, 26, 0, 0, 0, 'none', 0, 0, 0, 0),
(2, 'Emmett', 4, 4202, 294, 4, 44, 0, 'none', 0, 0, 20, 0),
(3, 'Emmettzzzz', 1, 100, 26, 0, 0, 0, 'none', 0, 0, 0, 0),
(4, 'Emmettzzzzzzz', 1, 100, 26, 0, 0, 0, 'none', 0, 0, 0, 0),
(5, 'testttt', 1, 100, 26, 0, 0, 0, 'none', 0, 0, 0, 0),
(6, 'testtttzzz', 1, 100, 26, 0, 0, 0, 'none', 0, 0, 0, 0),
(7, 'Emet_vajt', 1, 100, 26, 0, 0, 0, 'none', 0, 0, 0, 0),
(8, 'Emet_vajttt', 1, 100, 26, 0, 0, 0, 'none', 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `dealers`
--

CREATE TABLE `dealers` (
  `dealer_id` int(11) NOT NULL,
  `dealer_name` varchar(25) NOT NULL DEFAULT 'none',
  `dealer_skin` int(11) NOT NULL DEFAULT 29,
  `dealer_x` float NOT NULL DEFAULT 0,
  `dealer_y` float NOT NULL DEFAULT 0,
  `dealer_z` float NOT NULL DEFAULT 0,
  `dealer_a` float NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `fastfood`
--

CREATE TABLE `fastfood` (
  `ff_id` int(11) NOT NULL,
  `ff_x` float NOT NULL DEFAULT 0,
  `ff_y` float NOT NULL DEFAULT 0,
  `ff_z` float NOT NULL DEFAULT 0,
  `ff_rz` float NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `fastfood`
--

INSERT INTO `fastfood` (`ff_id`, `ff_x`, `ff_y`, `ff_z`, `ff_rz`) VALUES
(1, 140.823, -72.9489, 1.42969, 396.59),
(2, 134.785, -79.442, 1.42969, 246.941),
(3, 1397.41, -1748.55, 13.5469, 272.384),
(4, 1520.12, -1654.81, 13.5392, 447.164),
(5, 1830.39, -1269.46, 13.6245, 539.633),
(6, 1526.07, -1027.27, 23.9214, 335.54),
(7, 1240.58, -1030.65, 31.9496, 358.287),
(8, 1144, -931.836, 43.1405, 359.165),
(9, 718.902, -1123.92, 18.0111, 239.845),
(10, 662.913, -608.69, 16.3359, 537.251),
(11, 223.449, -157.607, 1.57813, 449.889),
(12, -75.2066, 1088.47, 19.7422, 487.907);

-- --------------------------------------------------------

--
-- Table structure for table `reports`
--

CREATE TABLE `reports` (
  `report_player` varchar(25) NOT NULL DEFAULT 'none',
  `report_reason` varchar(64) NOT NULL DEFAULT 'none'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `accounts`
--
ALTER TABLE `accounts`
  ADD PRIMARY KEY (`account_id`);

--
-- Indexes for table `characters`
--
ALTER TABLE `characters`
  ADD PRIMARY KEY (`char_id`);

--
-- Indexes for table `dealers`
--
ALTER TABLE `dealers`
  ADD PRIMARY KEY (`dealer_id`);

--
-- Indexes for table `fastfood`
--
ALTER TABLE `fastfood`
  ADD PRIMARY KEY (`ff_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `accounts`
--
ALTER TABLE `accounts`
  MODIFY `account_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `characters`
--
ALTER TABLE `characters`
  MODIFY `char_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `dealers`
--
ALTER TABLE `dealers`
  MODIFY `dealer_id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `fastfood`
--
ALTER TABLE `fastfood`
  MODIFY `ff_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
