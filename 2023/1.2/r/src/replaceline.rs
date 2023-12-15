const NUMLIST: [(&str, &str); 9] = [
    ("one", "1ne"),
    ("two", "2wo"),
    ("three", "3hree"),
    ("four", "4our"),
    ("five", "5ive"),
    ("six", "6ix"),
    ("seven", "7even"),
    ("eight", "8ight"),
    ("nine", "9ine"),
];

pub fn replaceline(line: String) -> String {
    let mut ret_str: String = line.clone();
    for i in 0..=line.len() {
        ret_str = NUMLIST.into_iter().fold(ret_str, |x, y| {
            let (first, last) = x.split_at(i);
            first.replace(y.0, y.1) + last
        });
    }
    ret_str
}
