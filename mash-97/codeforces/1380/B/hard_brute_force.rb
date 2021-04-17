
# defines a public method n_perm which produces (elements.length)**(positions)
# permutations for elements
# as an instance method to the array
class Array
  @n_perms = []
  def n_perm(p)
    @n_perms = []
    _n_perm_(self, p)
    return @n_perms
  end
  
  
  private
  def _n_perm_(elements_array, p, current_pos=0, temp_array=[])
    if current_pos == p then
      @n_perms << temp_array.clone
      return 
    end
    
    elements_array.each do |element|
      temp_array << element
      _n_perm_(elements_array, p, current_pos+1, temp_array)
      temp_array.pop()
    end
  end
end


# Hard Brute Force: because it just simply does the what the questions say
# For Codeforces/1380/B "Universal Solution" problem 
class UniversalSolution 
  
  # counts average wins for a given choices ca against the bot's sa
  def average_wins(sa, ca, n)
    wins = 0.0
    n.times do |nni|
      sub_wins = 0
      n.times do |ni|
	sub_wins += yield(sa[(nni+ni)%n], ca[ni]) == true ? 1 : 0;
      end
      wins += sub_wins.to_f
    end
    return wins/n
  end
  
  # simulation part
  def universal_solutions(sa)
    ups = ['R', 'P', 'S'].n_perm(sa.length())
    solutions = {}
    avw = -1.0
    
    ups.each do |up|
      temp_avw = average_wins(sa, up, sa.length) do |s,c|
	if (s=='R' and c=='P') or (s=='P' and c=='S') or (s=='S' and c=='R') then
	  true
	else
	  false
	end
      end
      
      if temp_avw == avw 
	solutions[temp_avw] << up
	
      elsif temp_avw > avw 
	solutions[temp_avw] = [up]
	avw = temp_avw
      end
    end
    
    return [solutions, avw]
  end
  
  def start(max_show=10)
    t = gets.to_i()
    t.times do 
      s = gets.chomp!
      s = s.split('')
      result_hash, max_av = universal_solutions(s)
      puts("max_average value is: #{max_av}")
      puts("Possible solutions: ")
      result_hash[max_av][0..max_show].each do |solution|
	puts("\t#{solution.to_s}")
      end
      puts()
    end
  end
  
end


