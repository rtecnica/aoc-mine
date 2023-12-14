module CalParser
  ( parseCalVal,
  )
where

import qualified Data.Text as T
import qualified Data.Text.ICU.Char as C
import qualified Data.Tuple as P

parseCalLine :: (T.Text -> Maybe (Char, T.Text)) -> T.Text -> Maybe Int
parseCalLine func line =
  case func line of
    Nothing -> Nothing
    Just (c, t) -> case C.digitToInt c of
      Nothing -> parseCalLine func t
      Just i -> Just i

parseCalVal :: T.Text -> Maybe Int
parseCalVal line =
  (+) <$> interVal <*> secondVal
  where
    firstVal = parseCalFw line
    secondVal = parseCalBw line
    interVal = (* 10) <$> firstVal
    parseCalFw = parseCalLine T.uncons
    parseCalBw = parseCalLine ((fmap . fmap) P.swap T.unsnoc)
