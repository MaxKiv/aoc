use std::{io, str::FromStr, fmt::Display};

#[derive(Debug)]
enum CubeColor {
    Blue,
    Red,
    Green,
}

impl FromStr for CubeColor {
    type Err = std::num::ParseIntError;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        match s {
            "blue" => Ok(CubeColor::Blue),
            "red" => Ok(CubeColor::Red),
            "green" => Ok(CubeColor::Green),
            &_ => panic!("Attempt to parse {} into a CubeColor", s)
        }
    }
}

#[derive(Debug)]
struct Draw {
    num: usize,
    color: CubeColor,
}

impl FromStr for Draw {
    type Err = std::num::ParseIntError;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let mut iter = s.split_whitespace();
        let num = iter.next().unwrap().parse()?;
        let color = CubeColor::from_str(iter.next().unwrap())?;
        Ok(Draw {num, color})
    }
}

impl Display for Draw {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{} {:#?}", self.num, self.color)
    }
}

#[derive(Debug)]
struct Game {
    id: u32,
    draws: Vec<Draw>,
}

impl FromStr for Game {
    type Err = std::num::ParseIntError;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let tokens: Vec<&str> = s.split(':').collect();
        let id = tokens[0].split_whitespace().skip(1).next().unwrap();
        let id = id.parse().unwrap();
        let draws = tokens[1].split([',',';']).filter_map(|token| Draw::from_str(token).ok()).collect();

        Ok( Game {id, draws})
    }
}

impl Display for Game {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{} - {:?}", self.id, self.draws)
    }
}

fn valid_game(game: &Game) -> bool {
    println!("{}", game);
    !game.draws.iter().any(|draw| match draw.color {
        CubeColor::Blue => draw.num > 14,
        CubeColor::Green => draw.num > 13,
        CubeColor::Red => draw.num > 12,
    })
}

fn part_1(input: &Vec<String>) -> u32 {
    input.iter()
        .filter_map(|line| Game::from_str(line).ok())
        .filter(|game| valid_game(game))
        .map(|game| game.id)
        .sum()
}

fn main() {

    let input: Vec<String> = io::stdin().lines().filter_map(Result::ok).collect::<Vec<String>>();

    println!("Part one: {}", part_1(&input));
    println!("Part two: {}", part_2(&input));
}

fn game_power(game: Game) -> usize {
    println!("game {}", game);
    let mut power: [usize; 3] = [0; 3];
    for draw in game.draws {
        match draw.color {
            CubeColor::Red => if draw.num > power[0] { power[0] = draw.num},
            CubeColor::Blue => if draw.num > power[1] { power[1] = draw.num},
            CubeColor::Green => if draw.num > power[2] { power[2] = draw.num},
        }
        println!("Power: {} {} {}", power[0], power[1], power[2]);
    }
    let total_power = power.iter().product();
    println!("{}", total_power);
    total_power
}

fn part_2(input: &Vec<String>) -> u32 {
    input.iter()
        .filter_map(|line| Game::from_str(line).ok())
        .map(|game| game_power(game) as u32)
        .sum()
}

