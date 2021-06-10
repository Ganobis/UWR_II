require 'test/unit'

class Palindrome
    def initialize
    end

    def palindrome?(str)
        str.downcase.tr('^a-z0–9', '') == str.downcase.tr('^a-z0–9', '').reverse
    end
end

class PalindromeTests < Test::Unit::TestCase
    @palindrome

    def setup
        @palindrome = Palindrome.new
    end

    def test_empty_str
        assert_equal(true,@palindrome.palindrome?(""))
    end
    def test_long
        assert_equal(true,@palindrome.palindrome?("A man, a plan, a canal -- Panama"))
    end
    def test_sentence
        assert_equal(true,@palindrome.palindrome?("Madam, I'm Adam!"))
    end
    def test_false
        assert_equal(false,@palindrome.palindrome?("Abracadabra"))
    end
end


class CountWords
    def initialize
    end

    def count_words(str)
        hashTable = Hash.new(0)
        str.downcase.split(" ").each { |word| hashTable[word.tr('^a-z0-9', '')] += 1 if word.tr('^a-z0-9', '') != ""}
        return hashTable
    end
end

class CountWordsTests < Test::Unit::TestCase
    @countwords

    def setup
        @countwords = CountWords.new
    end

    def test_empty_str
        assert_equal( {}, @countwords.count_words(""))
    end
    def test_long1
        assert_equal( {'a' => 3, 'man' => 1, 'canal' => 1, 'panama' => 1, 'plan' => 1}, @countwords.count_words("A man, a plan, a canal -- Panama"))
    end
    def test_long2
        assert_equal( {"pizza" => 4, "wloska" => 2, "z" => 2, "ananasem" => 1, "tunczykiem" => 1}, @countwords.count_words("Pizza Wloska - pizza z ananasem, pizza z tunczykiem, pizza Wloska"))
    end
end


class Same
    def initialize
    end

    def same23?(tab)
        hashTable = Hash.new(0)
        tab.each { |word| hashTable[word] += 1 }
        hashTable.has_value?(3) and hashTable.has_value?(2)
    end
end

class SameTests < Test::Unit::TestCase
    @same

    def setup
        @same = Same.new
    end

    def test_3a_2b
        assert_equal( true, @same.same23?(["a", "a", "a", "b", "b"]))
    end
    def test_1a_2b_2c
        assert_equal( false, @same.same23?(["a", "b", "c", "b", "c"]))
    end
    def test_5a
        assert_equal( false, @same.same23?(["a", "a", "a", "a", "a"]))
    end
end

class ReverseHash
    def initialize
    end

    def reve(hashTable)
        return hashTable.invert
    end
end

class ReverseHashTests < Test::Unit::TestCase
    @reversehash

    def setup
        @reversehash = ReverseHash.new
    end

    def test_empty_hash
        hash = {}
        assert_equal({}, @reversehash.reve(hash))
    end
    def test_list
        dict = {:one => 'jeden', :two => 'dwa', :three => 'trzy'}
        assert_equal({ 'jeden' => :one, 'dwa' => :two, 'trzy' => :three }, @reversehash.reve(dict))
    end
end