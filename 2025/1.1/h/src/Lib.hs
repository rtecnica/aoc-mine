{-# LANGUAGE OverloadedStrings #-}

module Lib
  ( parseMove,
    transitState
  )
where

import qualified Data.Text as T

data Direction = Left | Right
data Move = Move
    { dir :: !Direction,
      mag :: !Int
    }

parseMove :: T.Text -> Move
parseMove line = Move dir mag
    where
    d:m = T.unpack (T.strip line)
    dir = if d == 'R'
        then Lib.Right
        else Lib.Left
    mag = read m :: Int

rightMove :: Int -> Int -> Int
rightMove state move = mod (state + (mod move 100)) 100
 
leftMove :: Int -> Int -> Int
leftMove state move = mod ((state + 100) - (mod move 100)) 100

transitState :: (Int, Int) -> Move -> (Int, Int)
transitState (state, count) move = (new_state, new_count)
    where
    new_state = case dir move of
        Lib.Left -> leftMove state (mag move)
        Lib.Right -> rightMove state (mag move)
    new_count = count + extras
    extras = if (new_state == 0) 
            then 1
            else 0

