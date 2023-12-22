

#building hash map
 obj = {
  "2"=>"abc",
  "3"=>"def",
  "4"=> "ghi",
  "5"=>"jkl",
  "6"=>"mno",
  "7"=>"pqrs"
}

li=[];

def sol(str,i,ans,li,obj)

  if(str[i]==nil)
    li << ans;
    return;
  end


  #this is the crux of the question that i have to make multiple calls in it as according to the hash map
k = 0
  until (k==(obj[str[i]]).size )
    sol(str,i+1, ans +""+(obj[str[i]])[k] ,li,obj)
    k=k+1
  end
end

str = "234"
i=0
ans=""
sol(str,i,ans,li,obj)

puts "ans: "
p li.size
