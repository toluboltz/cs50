// Run script once DOM content is loaded
document.addEventListener('DOMContentLoaded', function() {

    let alertPlaceholder = document.getElementById('alert');
    let form = document.getElementById('form');

    function alert(message, type) {
        var wrapper = document.createElement('div');
        wrapper.innerHTML = '<div class="alert alert-' + type + ' alert-dismissible" role="alert">' + message + '<button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button></div>';

        alertPlaceholder.append(wrapper);
    }

    // When submit button on the form is clicked
    let submit = document.querySelector('#submit');
    submit.addEventListener('click', function() {
        alert('Submitted!', 'success');
        form.reset();
    })
})