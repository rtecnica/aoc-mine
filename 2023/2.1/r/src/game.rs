struct Bag {
    red: u8,
    green: u8,
    blue: u8,
}

struct Game {
    id: u8,
    sets: Option<Vec<Bag>>,
}

fn from_string(line: &str) -> Game {
    let new_game = Game { id: 1, sets: None };
    return new_game;
}
