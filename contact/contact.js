$(document).ready(function () {
    console.log("test");
    $.ajax({
        type: "POST",
        url: "index.php",
        data: $("#register-form").serialize(),
        success: function (result) {
            result=JSON.parse(result);
            console.log(result);
        }
    })
});