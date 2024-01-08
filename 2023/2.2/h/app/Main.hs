{-# LANGUAGE OverloadedStrings #-}

module Main (main) where

import qualified Data.Text as T
import qualified Data.Text.IO as TIO
import Lib

refBag :: Bag
refBag = Bag 12 13 14

main :: IO ()
main = do
  content <- TIO.readFile "../input.txt"
  let lns = T.lines content

  let gms = map parseGame lns
  let pgms = filter (isGamePossible refBag) gms

  let sum_index = sum (map idNum pgms)
  let sum_pow = sum (map (pow . minBag) gms)

  print sum_index
  print sum_pow
  where
    pow b = red b * blue b * green b
