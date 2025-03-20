const char PAGE_GALLERY[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Gallery - Airport of Ethiopia – Airport de Ethiopia</title>
    <link
      rel="icon"
      href="assets/cropped-LOGOS_LOGO-Aeroportos_de-Mocambique-192x192.png"
      type="image/png"
    />
    <style>
      /* General Styles */
      body {
        margin: 0;
        font-family: "MetricHPE", "Trebuchet MS", "Lucida Sans Unicode",
          "Lucida Grande", "Lucida Sans", Arial, sans-serif;
        background: linear-gradient(15deg, rgb(2, 21, 67), #0a192f);
      }

      /* Navigation Bar */
      #navbar {
        position: fixed;
        top: 0;
        left: 0;
        width: 100%;
        padding: 10px 20px;
        display: flex;
        justify-content: center;
        align-items: center;
        z-index: 1000;
        transition: background 0.3s ease;
      }

      .nav-container {
        display: flex;
        justify-content: space-between;
        align-items: center;
        width: 100%;
        max-width: 1200px;
      }

      .nav-logo-1 {
        width: 300px;
        height: 80px;
      }

      .nav-logo-2 {
        width: 150px;
        height: 80px;
      }

      .nav-links {
        display: flex;
        gap: 40px;
        font-size: 2em;
        text-transform: uppercase;
        list-style: none;
        margin: 0;
        padding: 0;
      }

      .nav-links a {
        text-decoration: none;
        color: #ffffff;
        font-weight: bold;
        transition: color 0.3s ease;
      }

      .nav-links a:hover {
        color: #0624b6;
      }

      /* Hamburger Menu */
      .hamburger {
        display: none;
        flex-direction: column;
        cursor: pointer;
        margin-right: 30px;
      }

      .hamburger span {
        width: 50px;
        height: 4px;
        background: #fff;
        margin: 4px 10px;
        transition: 0.3s;
        border-radius: 10px;
      }

      .hamburger.close span:nth-child(1) {
        transform: rotate(45deg) translate(6px, 12px);
      }

      .hamburger.close span:nth-child(2) {
        opacity: 0;
      }

      .hamburger.close span:nth-child(3) {
        transform: rotate(-45deg) translate(6px, -12px);
      }

      /* gallery */

      header {
        text-align: center;
        padding-top: 80px;
        color: #fff;
        text-transform: uppercase;
      }

      /* Gallery Layout */
      .gallery {
        display: grid;
        grid-template-columns: repeat(auto-fit, minmax(15%, 1fr));
        gap: 15px;
        padding: 20px;
      }

      .gallery-item {
        position: relative;
        overflow: hidden;
        border-radius: 10px 10px 1 0;
        box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);
        transition: transform 0.3s ease, box-shadow 0.3s ease;
      }

      .gallery-item.large {
        grid-column: span 2;
        grid-row: span 2;
      }

      .gallery-item img {
        width: 100%;
        height: 100%;
        object-fit: cover;
        transition: transform 0.3s ease;
      }

      /* Overlay and Text */
      .overlay {
        position: absolute;
        top: 0;
        left: 0;
        width: 100%;
        height: 100%;
        background: rgba(0, 0, 0, 0.5);
        display: flex;
        justify-content: center;
        align-items: center;
        opacity: 0;
        transition: opacity 0.3s ease;
      }

      .text {
        color: #fff;
        font-size: 1.5rem;
        text-align: center;
        transform: translateY(20px);
        transition: transform 0.3s ease;
      }

      /* Hover Effects */
      .gallery-item:hover {
        transform: scale(1.05);
        box-shadow: 0 8px 16px rgba(0, 0, 0, 0.3);
      }

      .gallery-item:hover img {
        transform: scale(1.1);
      }

      .gallery-item:hover .overlay {
        opacity: 1;
      }

      .gallery-item:hover .text {
        transform: translateY(0);
      }

      /* Footer Styles */

      footer {
        position: fixed;
        bottom: 0;
        left: 0;
        width: 100%;
        background-color: rgba(0, 0, 0, 0.7);
        color: #fff;
        text-align: center;
        padding: 10px 0;
        font-size: 1.2em;
        font-weight: 400;
      }

      footer a {
        color: #073e91;
        text-decoration: none;
        transition: color 0.3s ease;
      }

      footer a:hover {
        color: #fff;
      }

      /* Responsive Styles */
      @media (max-width: 768px) {
        header h1 {
          margin-top: 50px;
          font-size: 1rem;
        }

        .nav-links {
          display: none;
          flex-direction: column;
          position: absolute;
          top: 80px;
          left: 0;
          width: 100%;
          height: calc(100vh - 100px);
          border-radius: 30px 30px 0 0;
          background: rgba(77, 178, 245, 0.9);
          text-align: center;
        }

        .nav-links.active {
          display: flex;
        }

        .hamburger {
          display: flex;
        }

        .nav-logo-1,
        .nav-logo-2 {
          width: 80px;
          height: 40px;
        }

        footer {
          font-size: 0.64em;
        }
      }
    </style>
  </head>

  <body>
    <!-- Navigation Bar -->
    <nav id="navbar">
      <div class="nav-container">
        <img
          src="assets/cropped-Animated-Logo-500x500-px-5-removebg-preview.png"
          alt="Logo 1"
          class="nav-logo-1"
        />
        <ul class="nav-links">
          <li><a href="/">Home</a></li>
          <li><a href="/control">Control</a></li>
          <li><a href="/gallery">Gallery</a></li>
        </ul>
        <div class="hamburger" id="hamburger">
          <span></span>
          <span></span>
          <span></span>
        </div>
      </div>
    </nav>

    <header>
      <h1>Gallery - Projects & Experience</h1>
    </header>

    <div class="gallery">
      <!-- Images will be dynamically loaded here -->
    </div>

    <footer>
      &copy; 2025 Airport Control Panel | Developed & Powered by
      <a href="https://tech.happylight.rw/">Happy Light Tech Ltd</a> | All
      rights reserved.
    </footer>

    <script>
      // Function to load images from the SD card
      
        function loadGalleryImages() {
            fetch("/list-images")
                .then((response) => {
                    console.log("Response:", response);
                    return response.json();
                })
                .then((data) => {
                    console.log("Data:", data);
                    const gallery = document.querySelector('.gallery');
                    data.forEach((image, index) => {
                        const galleryItem = document.createElement('div');
                        galleryItem.classList.add('gallery-item');
                        const img = document.createElement('img');
                        img.src = image;
                        img.alt = `Project ${index + 1}`;
                        galleryItem.appendChild(img);
                        gallery.appendChild(galleryItem);
                    });
                })
                .catch((error) => console.error('Error loading images:', error));
        }
        window.onload = loadGalleryImages;

      // Navigation Bar Scroll Effect
      window.addEventListener("scroll", function () {
        const navbar = document.getElementById("navbar");
        const navLinks = document.querySelectorAll(".nav-links a");
        const hamburgerSpans = document.querySelectorAll(".hamburger span");

        if (window.scrollY > 50) {
          navbar.style.background = "#fff";
          hamburgerSpans.forEach((span) => (span.style.background = "#000"));
          navLinks.forEach((link) => (link.style.color = "#000"));
        } else {
          navbar.style.background = "transparent";
          hamburgerSpans.forEach((span) => (span.style.background = "#fff"));
          navLinks.forEach((link) => (link.style.color = "#fff"));
        }
      });

      // Hamburger Menu Toggle
      const hamburger = document.getElementById("hamburger");
      const navLinks = document.querySelector(".nav-links");

      hamburger.addEventListener("click", function () {
        navLinks.classList.toggle("active");
        hamburger.classList.toggle("close");
      });
    </script>
  </body>
</html>


    )=====";