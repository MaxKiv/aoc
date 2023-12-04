use std::{io, str::FromStr};

enum CubeColor {
    Blue,
    Red,
    Green,
}
impl FromStr for CubeColor {
    type Err = std::num::ParseIntError;

    fn from_str(s: &str) -> Result<Self, Self::Err> {

    }
}

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

struct Game {
    id: u32,
    colors: Vec<Draw>,
}

impl FromStr for Game {
    type Err = std::num::ParseIntError;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let id = *s.as_bytes().iter().skip(4).next().unwrap() as u32 - '0' as u32;
        let colors = s[6..].split(',').filter_map(|token| Draw::from_str(token).ok()).collect();

        Ok( Game {id, colors})
    }
}

fn main() {

    let input: Vec<String> = io::stdin().lines().filter_map(Result::ok).collect::<Vec<String>>();

    println!("Part one: {}", part_1(&input));
    // println!("Part two: {}", part_2(&input));
}

fn part_1(input: &Vec<String>) -> u32 {
    input.iter().map(|line| parse_game(line)).filter(|game| game_is_possible(game)).map(|game|
        id_of_game(game)).sum()
}

fn parse_game(line: &str) -> Game {
    let mut game: Game;
    game.id = line.chars().skip(4).next().unwrap().to_digit(10).unwrap();

    return game
}

// fn part_2(input: &Vec<String>) -> u32 {
//     input.iter().map(|line| parse_line_2(line)).sum()
// }

