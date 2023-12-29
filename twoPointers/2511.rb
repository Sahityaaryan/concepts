
forts=[0,-1,-1,0,-1]

#counting the distacne between by position

  def count_by_pos(my_fort,em_fort)
    if(my_fort>em_fort)
      my_fort-em_fort-1
    else
      em_fort-my_fort-1
    end
  end

  #using prefix sum actuall counting the number of zeroes between them
  def count_actual(my_fort,em_fort,count)
    if count[my_fort] > count[em_fort]
      count[my_fort]-count[em_fort]
    else
      count[em_fort]-count[my_fort]
    end
  end


  def capture_forts(forts)

    #answer array
    ans = 0

    #1. count array (prefix sum counting the actual zeroes in between)
    count = Array.new(forts.size,0);

    #prefix sum
    i = 1

    #O(N)
    until i==forts.size
      count[i] = count[i-1]+1 unless(forts[i]!=0)
      count[i] = count[i-1] unless(forts[i]==0)
      i=i+1
    end


    #2. solving the question

    my_fort = -1;
    em_fort =-1;

     #O(N)
    forts.each_with_index do |ele,i|
      if(ele==1)
        my_fort=i;
      elsif ele==-1
        em_fort=i
      end

   if(my_fort!=-1 && em_fort!=-1)
     a = count_by_pos(my_fort,em_fort)
    b = count_actual(my_fort,em_fort,count)
   end

    #if the number of zeroes between the forts and zero are same then
    #this will satisy the condition that whatever the numbers between them
  # are zero and thus we get the exact number of enemy forts

     if (a==b && a != nil)
      ans = a unless( a <= ans)
     end

    end
    ans

  end


puts "ans: "
p capture_forts(forts)


#TC = O(N)
# SC =  O(N)
