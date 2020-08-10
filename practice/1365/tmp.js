const express=require('express');
app=express();


app.get('/',function(req,res){
    if(err)throw err;
    res.render('3_1.html');
});


app.listen(3000,function(){
    console.log('Listening at 3000');
});


