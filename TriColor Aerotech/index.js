
    function scrollToSection(sectionId) {
        document.getElementById(sectionId).scrollIntoView({
            behavior: 'smooth'
        });
    }


    document.addEventListener('DOMContentLoaded', function () {
        const switchInput = document.getElementById('s1-57');
        const htmlElement = document.querySelector('html');
  
        switchInput.addEventListener('change', function () {
          if (switchInput.checked) {
            htmlElement.setAttribute('data-bs-theme', 'dark'); // Set to dark mode
          } else {
            htmlElement.setAttribute('data-bs-theme', 'light'); // Set to light mode
          }
        });
      });