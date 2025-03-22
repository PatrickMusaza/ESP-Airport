
// Carousel
let currentSlide = 0;
const slides = document.querySelectorAll('.carousel-slide');

function showSlide(index) {
    slides.forEach((slide, i) => {
        slide.classList.toggle('active', i === index);
    });
}

function nextSlide() {
    currentSlide = (currentSlide + 1) % slides.length;
    showSlide(currentSlide);
}

function prevSlide() {
    currentSlide = (currentSlide - 1 + slides.length) % slides.length;
    showSlide(currentSlide);
}

setInterval(nextSlide, 5000);

// Navigation Bar Scroll Effect
window.addEventListener('scroll', function () {
    const navbar = document.getElementById('navbar');
    const navLinks = document.querySelectorAll('.nav-links a');
    const hamburgerSpans = document.querySelectorAll('.hamburger span');  // Correcting this

    if (window.scrollY > 50) {
        navbar.style.background = '#fff';
        hamburgerSpans.forEach(span => span.style.background = '#000');  // Apply background to each span
        navLinks.forEach(link => link.style.color = '#000');

        addLinkHoverEffect(navLinks, '#1925B0FF', '#000');
    } else {
        navbar.style.background = 'transparent';
        hamburgerSpans.forEach(span => span.style.background = '#fff');  // Apply background to each span
        navLinks.forEach(link => link.style.color = '#fff');

        addLinkHoverEffect(navLinks, '#1925B0FF', '#fff');
    }
});

// Helper function to avoid duplicated code for hover effect
function addLinkHoverEffect(navLinks, hoverColor, originalColor) {
    navLinks.forEach(link => {
        link.addEventListener('mouseover', () => {
            link.style.color = hoverColor;  // Color on hover
        });

        link.addEventListener('mouseout', () => {
            link.style.color = originalColor;  // Color when hover ends
        });
    });
}

// Hamburger Menu Toggle
const hamburger = document.getElementById('hamburger');
const navLinks = document.querySelector('.nav-links');

hamburger.addEventListener('click', function () {
    navLinks.classList.toggle('active');
    hamburger.classList.toggle('close');
});

// Carousel Arrows
document.getElementById('prevSlide').addEventListener('click', prevSlide);
document.getElementById('nextSlide').addEventListener('click', nextSlide);

// Event listener for the Home link
document.getElementById('home-link').addEventListener('click', function (event) {
    event.preventDefault(); // Prevent default link behavior
    console.log('Home link clicked');
    loadContent('index.html');
});

//Control.html

function toggleLight(lightNumber) {
    const lightCard = document.getElementById(`light-card-${lightNumber}`);
    const switchInput = document.getElementById(`switch${lightNumber}`);
    const status = lightCard.querySelector(".light-status");

    const isOn = switchInput.checked;
    const state = isOn ? "on" : "off";

    fetch(`/control?device=relay${lightNumber}&state=${state}`)
        .then((response) => {
            if (response.ok) {
                lightCard.classList.toggle("on", isOn);
                status.textContent = `Status: ${isOn ? "On" : "Off"}`;
                switchInput.checked = isOn;
            } else {
                console.error("Failed to toggle relay");
                switchInput.checked = !isOn;
            }
        })
        .catch((error) => {
            console.error("Error:", error);
            switchInput.checked = !isOn;
        });
}

function expandPreview(lightNumber) {
    const previewArea = document.querySelector(".preview-area");
    const previewImages = document.querySelectorAll(".preview-area img");

    previewImages.forEach((img) => {
        img.style.gridColumn = "";
        img.style.gridRow = "";
        img.style.height = "";
    });

    const clickedImage = previewImages[lightNumber - 1];
    clickedImage.style.gridColumn = "1/3";
    clickedImage.style.gridRow = "1/3";
    clickedImage.style.height = "100vh";

    previewImages.forEach((img, index) => {
        if (index + 1 !== lightNumber) {
            img.style.height = "30vh";
        }
    });
}