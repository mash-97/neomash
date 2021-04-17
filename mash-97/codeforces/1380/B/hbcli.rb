require "thor"
require_relative("hard_brute_force")

class UniversalSolutionCli < Thor
  desc "usf INPUT_FILE", "run universal solutions on input file INPUT_FILE"
  option :max_show, type: :numeric, default: 10
  def usf(input_file)
    input_file = File.open(input_file, "r")
    input_lines = input_file.readlines()
    
    t = input_lines[0].to_i
    t.times do |i|
      s = input_lines[i+1]
      puts("Bot String: #{s}")
      s = s.split('')
      us = UniversalSolution.new()
      result_hash, max_av = us.universal_solutions(s)
      puts("max_average value is: #{max_av}")
      puts("Possible solutions(#{result_hash[max_av].length()} available | try showing #{options[:max_show]}): ")
      result_hash[max_av][0..options[:max_show]].each do |solution|
	puts("\t#{solution.to_s} ==>\t#{solution.join()}")
      end
      puts()
    end
  end
  
  desc "usf BOT_STRING", "run universal solutions on BOT_STRING"
  option :max_show, type: :numeric, default: 10
  def us(bot_string)
    s = bot_string
    puts("Bot String: #{s}")
    s = s.split('')
    us = UniversalSolution.new()
    result_hash, max_av = us.universal_solutions(s)
    puts("max_average value is: #{max_av}")
    puts("Possible solutions(#{result_hash[max_av].length()} available | try showing #{options[:max_show]}): ")
    result_hash[max_av][0..options[:max_show]].each do |solution|
      puts("\t#{solution.to_s} ==>\t#{solution.join()}")
    end
    puts()
  end
end

UniversalSolutionCli.start(ARGV)
