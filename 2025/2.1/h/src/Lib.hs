{-# LANGUAGE OverloadedStrings #-}

module Lib
  ( parseRange,
    getRepeats,
    getOrder,
    genDivs,
    getDivs,
    areDivs
  )
where

import qualified Data.Text as T

type Range = (Int, Int)

inRange :: Int -> Range -> Bool
inRange num range =
    if num < snd range && num > fst range
    then True
    else False

parseRange :: T.Text -> Range
parseRange line = (btm, top)
    where
    btm = read aa :: Int
    top = read bb :: Int
    aa = (T.unpack a)
    (_:bb) = (T.unpack b)
    (a, b) = T.breakOn "-" line

getOrder :: Int -> Int
getOrder num = (floor . (logBase 10)) (fromIntegral num) + 1

getDivs :: Int -> [Int]
getDivs num = if mod num 2 == 0
                then [(div num 2)]
                else []

genDivs :: Int -> [Int]
genDivs order = map gendiv divs 
    where 
    reps = \x -> replicate (div order x) x
    gendiv = (foldl genstep 0) . reps
    genstep = \x y -> (x * 10^y) + 1 
    divs = getDivs order

areDivs :: Int -> Bool
areDivs num = foldl (||) False arrays 
    where
    arrays = map (\x -> (mod num x) == 0) (divs num)
    divs = (genDivs . getOrder)

getRepeats :: Range -> [Int]
getRepeats (start, stop) = filter (\x -> areDivs x) range 
    where
    range = [start..stop] 
