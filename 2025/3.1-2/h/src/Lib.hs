{-# LANGUAGE OverloadedStrings #-}

module Lib
  ( dropBatt,
    parseLine,
    getMaxJoltage,
    slice,
    chop
  )
where

import qualified Data.Text as T
import qualified Data.Char as C

parseLine :: T.Text -> [Int]
parseLine line = 
  map C.digitToInt (T.unpack line)

dropBatt :: [Int] -> [Int]
dropBatt (x:xs) = 
  if xs == [] || (x < head xs) 
  then xs
  else x:dropBatt xs

getMaxJolts :: [Int] -> [Int] -> [Int]
getMaxJolts array (y:ys) = 
  if (array /= []) 
  then if x >= y 
       then getMaxJolts xs (x:(dropBatt (y:ys)))
       else getMaxJolts xs (y:ys)
  else (y:ys)
  where
    (x:xs) = array
       
slice :: Int -> Int -> [Int] -> [Int]
slice start stop arr =
  map (\x -> arr!!x) [start..stop]

chop :: Int -> [Int] -> ([Int], [Int]) 
chop size x = (reverse (slice 0 ((length x) - size - 1) x), slice ((length x) - size) ((length x) - 1) x)

getMaxJoltage :: Int -> [Int] -> Int 
getMaxJoltage size line = joltArrToInt (lineToJolts line)
  where
  joltArrToInt = foldl (\x y -> x * 10 + y) 0
  lineToJolts = \x -> getMaxJolts ((fst . (chop size)) x) ((snd . (chop size)) x)
