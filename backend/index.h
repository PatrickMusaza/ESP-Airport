
const char PAGE_MAIN[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Airport of Ethiopia – Airport de Ethiopia</title>
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

      /* Hero Carousel */
      #hero-carousel {
        position: relative;
        height: 100vh;
        overflow: hidden;
      }

      .carousel-container {
        position: relative;
        height: 100%;
      }

      .carousel-slide {
        position: absolute;
        top: 0;
        left: 0;
        width: 100%;
        height: 100%;
        opacity: 0;
        transition: opacity 1s ease;
      }

      .carousel-slide.active {
        opacity: 1;
      }

      .carousel-slide img {
        width: 100%;
        height: 100%;
        object-fit: cover;
        animation: slideFromRight 1s ease forwards;
        /* Animate the image from the right */
      }

      .carousel-content {
        position: absolute;
        top: 50%;
        left: 50%;
        transform: translate(-50%, -50%);
        text-align: center;
        color: #fff;
        opacity: 0;
        transition: opacity 1s ease, transform 1s ease;
      }

      .carousel-slide.active .carousel-content {
        opacity: 1;
        transform: translate(-50%, -50%);
      }

      .carousel-content h1 {
        font-size: 4rem;
        margin: 0;
        animation: slideInFromTop 1s ease forwards;
        /* Animate title from top */
      }

      .carousel-content p {
        font-size: 1.8rem;
        margin: 10px 0 0;
        animation: slideInFromBottom 1s ease forwards 0.5s;
        /* Animate description from bottom */
      }

      /* Keyframes for Animations */

      /* Image sliding from right */
      @keyframes slideFromRight {
        from {
          transform: translateX(100%);
          opacity: 0;
        }

        to {
          transform: translateX(0);
          opacity: 1;
        }
      }

      /* Title sliding in from the top */
      @keyframes slideInFromTop {
        from {
          transform: translateY(-100%);
          opacity: 0;
        }

        to {
          transform: translateY(0);
          opacity: 1;
        }
      }

      /* Description sliding in from the bottom */
      @keyframes slideInFromBottom {
        from {
          transform: translateY(100%);
          opacity: 0;
        }

        to {
          transform: translateY(0);
          opacity: 1;
        }
      }

      /* Carousel Arrows */
      .carousel-arrow {
        position: absolute;
        top: 50%;
        transform: translateY(-50%);
        font-size: 2rem;
        color: #fff;
        cursor: pointer;
        opacity: 0;
        transition: opacity 0.3s ease;
      }

      .carousel-arrow.left {
        left: 20px;
      }

      .carousel-arrow.right {
        right: 20px;
      }

      #hero-carousel:hover .carousel-arrow {
        opacity: 1;
      }

      /* Company Section */
      .company-section {
        display: flex;
        align-items: center;
        justify-content: center;
        padding: 50px 20px;
        background-color: #f9f9f9;
      }

      .company-content {
        display: flex;
        align-items: center;
        max-width: 1200px;
        width: 100%;
      }

      .company-image {
        flex: 1;
        margin-right: 40px;
      }

      .company-image img {
        width: 100%;
        height: auto;
        border-radius: 10px;
      }

      .company-text {
        flex: 2;
      }

      .company-text h2 {
        font-size: 2.5rem;
        margin-bottom: 20px;
      }

      .company-text p {
        font-size: 1.2rem;
        line-height: 1.6;
        margin-bottom: 20px;
      }

      .read-more {
        display: inline-block;
        padding: 10px 20px;
        background-color: #0425c9;
        color: #fff;
        text-decoration: none;
        border-radius: 5px;
        transition: background-color 0.3s ease;
      }

      .read-more:hover {
        background-color: #001849;
      }

      /* Fixed Background Image */
      .fixed-background {
        height: 400px;
        background-image: url("assets/IMG-20250315-WA0042.jpg");
        background-attachment: fixed;
        background-position: center;
        background-repeat: no-repeat;
        background-size: cover;
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
        #dynamic-content h1 {
          margin-top: 50px;
          margin-bottom: 50px;
          font-size: 1rem;
        }

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

        .carousel-content h1 {
          font-size: 2rem;
        }

        .carousel-content p {
          font-size: 1rem;
        }

        .company-content {
          flex-direction: column;
        }

        .company-image {
          margin-right: 0;
          margin-bottom: 20px;
        }

        .company-text h2 {
          font-size: 2rem;
        }

        .company-text p {
          font-size: 1rem;
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

    <!-- Main Content -->
    <div id="main-content">
      <!-- Hero Carousel -->
      <section id="hero-carousel">
        <div class="carousel-container">
          <div class="carousel-slide active">
            <img
              src="assets/Aeroportos__de_Mocambique-40.jpg"
              alt="Carousel 1"
            />
            <div class="carousel-content">
              <h1>Welcome to Aeroportos de Ethiopia</h1>
              <p>Your gateway to Ethiopia's beauty and culture.</p>
            </div>
          </div>
          <div class="carousel-slide">
            <img
              src="assets/Aeroportos__de_Mocambique-47.jpg"
              alt="Carousel 2"
            />
            <div class="carousel-content">
              <h1>Modern Facilities</h1>
              <p>Experience world-class amenities and services.</p>
            </div>
          </div>
          <div class="carousel-slide">
            <img src="assets/IMG-20250315-WA0016.jpg" alt="Carousel 3" />
            <div class="carousel-content">
              <h1>Efficient Operations</h1>
              <p>Ensuring smooth and timely travel for all passengers.</p>
            </div>
          </div>
          <div class="carousel-slide">
            <img src="assets/IMG-20250315-WA0030.jpg" alt="Carousel 4" />
            <div class="carousel-content">
              <h1>Explore Ethiopia</h1>
              <p>Discover the vibrant culture and stunning landscapes.</p>
            </div>
          </div>
          <div class="carousel-slide">
            <img src="assets/WhatsApp Image 2025-03-15.jpg" alt="Carousel 5" />
            <div class="carousel-content">
              <h1>Your Journey Starts Here</h1>
              <p>We are committed to making your travel seamless.</p>
            </div>
          </div>
        </div>
        <!-- Carousel Arrows -->
        <div class="carousel-arrow left" id="prevSlide">&#10094;</div>
        <div class="carousel-arrow right" id="nextSlide">&#10095;</div>
      </section>

      <!-- Section for ADB Safegate -->
      <section class="company-section" id="adb-safegate">
        <div class="company-content">
          <div class="company-image">
            <img
              src="assets/cropped-Animated-Logo-500x500-px-5-removebg-preview.png"
              alt="ADB Safegate"
            />
          </div>
          <div class="company-text">
            <h2>ADB Safegate</h2>
            <p>Empowering the Airside Evolution</p>
            <p>
              ADB SAFEGATE provides intelligent solutions empowering airports
              who are committed to evolving their airside ecosystem. Our Airside
              4.0 strategy connects airside assets to deliver real-time insights
              for advanced decision making, enhancing safety, efficiency, and
              sustainability across the entire airside ecosystem.
            </p>
            <a href="https://adbsafegate.com/" class="read-more">Read More</a>
          </div>
        </div>
      </section>

      <!-- Fixed Background Image -->
      <div class="fixed-background"></div>

      <!-- Section for HappyLight Tech -->
      <section class="company-section" id="happylight-tech">
        <div class="company-content">
          <div class="company-image">
            <img src="assets/HLR Logo HD.png" alt="HappyLight Tech" />
          </div>
          <div class="company-text">
            <h2>HappyLight Tech</h2>
            <p>IT and IoT Solutions for Your Business</p>
            <p>
              From IoT solutions to web development, CCTV installation to 3D
              design, we offer a wide range of services to help you and your
              business succeed. Our team of experienced professionals is here to
              help you every step of the way, from consultation to
              implementation.
            </p>
            <a href="https://tech.happylight.rw/" class="read-more"
              >Read More</a
            >
          </div>
        </div>
      </section>
    </div>

    <!-- Footer Section -->

    <footer>
      &copy; 2025 Airport Control Panel | Developed & Powered by
      <a href="https://tech.happylight.rw/">Happy Light Tech Ltd</a> | All
      rights reserved.
    </footer>

    <script>
      // Carousel
      let currentSlide = 0;
      const slides = document.querySelectorAll(".carousel-slide");

      function showSlide(index) {
        slides.forEach((slide, i) => {
          slide.classList.toggle("active", i === index);
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
      window.addEventListener("scroll", function () {
        const navbar = document.getElementById("navbar");
        const navLinks = document.querySelectorAll(".nav-links a");
        const hamburgerSpans = document.querySelectorAll(".hamburger span"); // Correcting this

        if (window.scrollY > 50) {
          navbar.style.background = "#fff";
          hamburgerSpans.forEach((span) => (span.style.background = "#000")); // Apply background to each span
          navLinks.forEach((link) => (link.style.color = "#000"));

          addLinkHoverEffect(navLinks, "#1925B0FF", "#000");
        } else {
          navbar.style.background = "transparent";
          hamburgerSpans.forEach((span) => (span.style.background = "#fff")); // Apply background to each span
          navLinks.forEach((link) => (link.style.color = "#fff"));

          addLinkHoverEffect(navLinks, "#1925B0FF", "#fff");
        }
      });

      // Helper function to avoid duplicated code for hover effect
      function addLinkHoverEffect(navLinks, hoverColor, originalColor) {
        navLinks.forEach((link) => {
          link.addEventListener("mouseover", () => {
            link.style.color = hoverColor; // Color on hover
          });

          link.addEventListener("mouseout", () => {
            link.style.color = originalColor; // Color when hover ends
          });
        });
      }

      // Hamburger Menu Toggle
      const hamburger = document.getElementById("hamburger");
      const navLinks = document.querySelector(".nav-links");

      hamburger.addEventListener("click", function () {
        navLinks.classList.toggle("active");
        hamburger.classList.toggle("close");
      });

      // Carousel Arrows
      document.getElementById("prevSlide").addEventListener("click", prevSlide);
      document.getElementById("nextSlide").addEventListener("click", nextSlide);
    </script>
  </body>
</html>


)=====";