{-# LANGUAGE OverloadedStrings #-}

module Lib
  ( Bag (..),
    Game (..),
    parseGame,
    isGamePossible,
    minBag,
  )
where

import qualified Data.Text as T

data Colors = Colors
  { redC :: !T.Text,
    greenC :: !T.Text,
    blueC :: !T.Text
  }

colors :: Colors
colors = Colors "red" "green" "blue"

data Bag = Bag
  { red :: !Int,
    green :: !Int,
    blue :: !Int
  }

data Game = Game
  { idNum :: !Int,
    sets :: ![Bag]
  }

parseGame :: T.Text -> Game
parseGame line =
  Game new_id bag_list
  where
    new_id = parseGameId c
    bag_list = map parseGameSet set
    (c, s) = T.breakOn ":" line
    set = T.splitOn ";" (T.drop 2 s)

parseGameId :: T.Text -> Int
parseGameId substr =
  read (T.unpack (T.strip s)) :: Int
  where
    (_, s) = T.breakOn " " substr

parseGameSet :: T.Text -> Bag
parseGameSet substr =
  Bag r g b
  where
    s = map T.strip (T.splitOn "," substr)
    r = foldr ((+) . parseColor (redC colors)) 0 s
    g = foldr ((+) . parseColor (greenC colors)) 0 s
    b = foldr ((+) . parseColor (blueC colors)) 0 s

parseColor :: T.Text -> T.Text -> Int
parseColor color substr =
  if T.isInfixOf color substr
    then read (T.unpack (T.strip s)) :: Int
    else 0
  where
    (s, _) = T.breakOn " " substr

isGamePossible :: Bag -> Game -> Bool
isGamePossible b g =
  and bools
  where
    bools = map (isSetPossible b) (sets g)

isSetPossible :: Bag -> Bag -> Bool
isSetPossible b s =
  and (zipWith (>=) bs ss)
  where
    bs = [red, green, blue] <*> [b]
    ss = [red, green, blue] <*> [s]

minBag :: Game -> Bag
minBag g =
  Bag minRed minBlue minGreen
  where
    minRed = foldr (max . red) 0 (sets g)
    minBlue = foldr (max . blue) 0 (sets g)
    minGreen = foldr (max . green) 0 (sets g)
