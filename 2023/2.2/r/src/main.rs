use std::fs::read_to_string;

mod game;
use game::*;

fn main() {
    let ref_bag = Bag {
        red: 12,
        blue: 14,
        green: 13,
    };

    let lines = read_to_string("../input.txt").unwrap();

    let lines2 = &lines;
    let lines3 = &lines;

    let parsed_games2 = lines2.lines().map(|line| from_string(line));
    let parsed_games3 = lines3.lines().map(|line| from_string(line));

    let running_sum: u32 = parsed_games2
        .filter(|curr_game| is_game_possible(&ref_bag, &curr_game))
        .map(|curr_game: Game| curr_game.id)
        .fold(0, |acc, item| acc + (item as u32));

    println!("{}", running_sum);

    let power_sum: u32 = parsed_games3
        .map(|g: Game| min_bag(g))
        .map(|b: Bag| (b.red as u32) * (b.blue as u32) * (b.green as u32))
        .fold(0, |acc, item| acc + (item as u32));

    println!("{}", power_sum);
}
