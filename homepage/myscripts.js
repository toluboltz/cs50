// Run script once DOM content is loaded
document.addEventListener('DOMContentLoaded', function() {

    // When submit button on the form is clicked
    let submit = document.querySelector('.submit');
    submit.addEventListener('click', function() {
        submit.style.backgroundColor = 'green';
        doucment.querySelector('#feedback').innerHTML = 'Submitted!';
    })
})