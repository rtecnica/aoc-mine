use std::fs::read_to_string;

mod game;
use game::*;

fn main() {
    let ref_bag = Bag {
        red: 12,
        blue: 14,
        green: 13,
    };

    let running_sum: u32 = read_to_string("../input.txt")
        .unwrap()
        .lines()
        .map(|line| from_string(line))
        .filter(|curr_game| is_game_possible(&ref_bag, &curr_game))
        .map(|curr_game: Game| curr_game.id)
        .fold(0, |acc, item| acc + (item as u32));

    println!("{}", running_sum);
}
