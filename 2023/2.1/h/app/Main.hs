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
  let gms = filter (isGamePossible refBag) (map parseGame lns)
  let sum_index = sum (map idNum gms)
  print sum_index
