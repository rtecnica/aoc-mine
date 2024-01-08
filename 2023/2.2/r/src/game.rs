pub struct Bag {
    pub red: u8,
    pub green: u8,
    pub blue: u8,
}

pub struct Game {
    pub id: u8,
    sets: Vec<Bag>,
}

pub fn from_string(line: &str) -> Game {
    let mut new_game = Game {
        id: 1,
        sets: vec![],
    };

    let mut line_chunks = line.split(':');
    new_game.id = line_chunks
        .next()
        .unwrap()
        .split(' ')
        .next_back()
        .unwrap()
        .parse()
        .unwrap_or(0);
    new_game.sets = parse_sets(line_chunks.next().unwrap());
    return new_game;
}

fn parse_sets(substr: &str) -> Vec<Bag> {
    let mut sets: Vec<Bag> = vec![];
    for set_str in substr.trim().split(';') {
        let mut bag = Bag {
            red: 0,
            blue: 0,
            green: 0,
        };
        for bag_str in set_str.trim().split(',') {
            let mut bag_str_items = bag_str.trim().split(' ');
            let num = bag_str_items.next().unwrap();
            match bag_str_items.next().unwrap() {
                "red" => bag.red = num.parse().unwrap(),
                "blue" => bag.blue = num.parse().unwrap(),
                "green" => bag.green = num.parse().unwrap(),
                _ => println!("Somthings gone wrong!"),
            }
        }
        sets.push(bag);
    }
    sets
}

pub fn is_game_possible(bag: &Bag, game: &Game) -> bool {
    let get_colors = |g: &Bag| vec![g.red, g.blue, g.green].into_iter();
    *(&game.sets[..]
        .into_iter()
        .map(|x: &Bag| {
            get_colors(&x)
                .zip(get_colors(bag))
                .fold(true, |acc, (a, b)| (a <= b) && acc)
        })
        .fold(true, |acc, i| i && acc))
}

pub fn min_bag(game: Game) -> Bag {
    let mut bag = Bag {
        red: 0,
        blue: 0,
        green: 0,
    };

    bag.red = *(&game.sets[..]
        .into_iter()
        .map(|d: &Bag| d.red)
        .max()
        .unwrap());
    bag.blue = *(&game.sets[..]
        .into_iter()
        .map(|b: &Bag| b.blue)
        .max()
        .unwrap());
    bag.green = *(&game.sets[..]
        .into_iter()
        .map(|b: &Bag| b.green)
        .max()
        .unwrap());

    bag
}
