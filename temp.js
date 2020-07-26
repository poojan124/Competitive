function makeInputVerifier(minimun, maximum){
    function foo(x){
        if(x > maximum){
            return "Input is more than maximum value";
        }
        else if(x < minimun){
            return "Input is less than minimum value";
        }
        else{
            return "Input is in range"; 
        }
    }
    return foo;
}

console.log(makeInputVerifier(10,20)(15));