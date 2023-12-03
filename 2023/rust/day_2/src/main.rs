use std::{io, str::FromStr};

enum CubeColors {
    Blue,
    Red,
    Green,
}

struct Game {
    id: u32,
    colors: Vec<CubeColors>,
}

impl FromStr for Game {
    type Err = std::num::ParseIntError;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let id = s.chars().skip(4).next()?.to_digit(10)?;

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
    game. kk

    return game
}

// fn part_2(input: &Vec<String>) -> u32 {
//     input.iter().map(|line| parse_line_2(line)).sum()
// }

