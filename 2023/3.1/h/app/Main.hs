{-# LANGUAGE OverloadedStrings #-}

module Main (main) where

import qualified Data.Array as A
import qualified Data.Text as T
import qualified Data.Text.IO as TIO
import Lib

main :: IO ()
main = do
  content <- TIO.readFile "../input.txt"

  let partNums = A.assocs (Lib.parsePartNum content)
  let syms = Lib.parseSymbol content

  let results = map (\x -> filter (Lib.isPartNum syms (fst x)) (A.elems (snd x))) partNums
  let numResults = map (map (read . T.unpack . fst)) results :: [[Int]]
  let partsum = sum $ map sum numResults
  print partsum
