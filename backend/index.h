
const char PAGE_MAIN[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Airport Control Panel - Home</title>
    <style>
      * {
        margin: 0;
        padding: 0;
        box-sizing: border-box;
      }

      body,
      html {
        height: 100%;
        overflow: hidden;
      }

      /* Scene Container */
      .scene {
        width: 100%;
        height: 100vh;
        position: relative;
        perspective: 1000px;
        background: linear-gradient(to bottom, #87ceeb, #b0e0e6);
        overflow: hidden;
      }

      /* Runway */
      .runway {
        position: absolute;
        bottom: 0;
        left: 50%;
        transform: translateX(-50%) rotateX(60deg);
        width: 80%;
        height: 40%;
        background: #808080;
        border-left: 10px dashed #fff;
        border-right: 10px dashed #fff;
        transform-style: preserve-3d;
      }

      /* Runway Lights */
      .runway-lights {
        position: absolute;
        bottom: 40%;
        left: 50%;
        transform: translateX(-50%) rotateX(60deg);
        width: 80%;
        height: 2px;
        background: repeating-linear-gradient(
          to right,
          #fff 0%,
          #fff 5%,
          transparent 5%,
          transparent 10%
        );
        transform-style: preserve-3d;
      }

      /* Terminal Building */
      .terminal {
        position: absolute;
        bottom: 40%;
        left: 10%;
        width: 20%;
        height: 30%;
        background: #a9a9a9;
        border: 5px solid #696969;
        transform: rotateX(60deg) translateZ(50px);
        transform-style: preserve-3d;
      }

      /* Control Tower */
      .control-tower {
        position: absolute;
        bottom: 60%;
        left: 70%;
        width: 5%;
        height: 20%;
        background: #d3d3d3;
        border: 5px solid #696969;
        transform: rotateX(60deg) translateZ(100px);
        transform-style: preserve-3d;
      }

      /* Planes */
      .plane {
        position: absolute;
        width: 10%;
        height: 10%;
        background: #ffffff;
        clip-path: polygon(
          0% 50%,
          20% 50%,
          20% 40%,
          40% 40%,
          40% 60%,
          20% 60%,
          20% 50%,
          100% 50%,
          80% 30%,
          80% 70%
        );
        transform-style: preserve-3d;
      }

      .plane-1 {
        bottom: 45%;
        left: 15%;
        transform: rotateX(60deg) translateZ(100px);
        animation: fly 10s linear infinite;
      }

      .plane-2 {
        bottom: 50%;
        left: 50%;
        transform: rotateX(60deg) translateZ(150px);
        animation: fly 8s linear infinite;
      }

      /* Plane Animation */
      @keyframes fly {
        0% {
          transform: rotateX(60deg) translateZ(100px) translateX(-100%);
        }
        100% {
          transform: rotateX(60deg) translateZ(100px) translateX(100%);
        }
      }

      /* Sky */
      .sky {
        position: absolute;
        top: 0;
        left: 0;
        width: 100%;
        height: 100%;
        background: linear-gradient(
          to bottom,
          rgba(135, 206, 235, 0.8),
          rgba(176, 224, 230, 0.8)
        );
        transform: translateZ(-500px);
        transform-style: preserve-3d;
      }

      /* Content Section */
      .content {
        position: absolute;
        top: 50%;
        left: 50%;
        transform: translate(-50%, -50%);
        text-align: center;
        color: #fff;
        z-index: 10;
        background: rgba(0, 0, 0, 0.7);
        padding: 20px;
        border-radius: 10px;
      }

      .content h1 {
        font-size: 2.5rem;
        margin-bottom: 10px;
      }

      .content p {
        font-size: 1.2rem;
        margin-bottom: 20px;
      }

      .content a {
        color: #28a745;
        text-decoration: none;
        font-weight: bold;
      }

      .content a:hover {
        text-decoration: underline;
      }

      /* Video Section */
      .video-container {
        margin-top: 20px;
      }

      .video-container iframe {
        width: 100%;
        height: 300px;
        border: none;
        border-radius: 10px;
      }

      /* Image Gallery */
      .image-gallery {
        display: grid;
        grid-template-columns: repeat(5, 1fr);
        gap: 10px;
        margin-top: 20px;
      }

      .image-gallery img {
        width: 100%;
        height: 150px;
        object-fit: cover;
        border-radius: 10px;
        transition: transform 0.3s, box-shadow 0.3s;
      }

      .image-gallery img:hover {
        transform: scale(1.1);
        box-shadow: 0 8px 12px rgba(0, 0, 0, 0.5);
      }

      /* Control Button */
      .control-button {
        margin-top: 20px;
        padding: 10px 20px;
        font-size: 16px;
        background-color: #28a745;
        color: #fff;
        border: none;
        border-radius: 5px;
        cursor: pointer;
      }

      .control-button:hover {
        background-color: #218838;
      }
    </style>
  </head>
  <body>
    <!-- 3D Airport Scene -->
    <div class="scene">
      <!-- Runway -->
      <div class="runway"></div>
      <!-- Runway Lights -->
      <div class="runway-lights"></div>
      <!-- Terminal Building -->
      <div class="terminal"></div>
      <!-- Control Tower -->
      <div class="control-tower"></div>
      <!-- Planes -->
      <img
        class="plane-1"
        src="https://www.pngplay.com/wp-content/uploads/12/Plane-PNG-Photo-Clip-Art-Image.png"
        height="100%"
        width="50%"
      />
      <div class="plane plane-2"></div>
      <!-- Sky -->
      <div class="skys"></div>
    </div>

    <!-- Content Section -->
    <div class="content">
      <h1>Airport Control Panel</h1>
      <p>
        Developed by the team at
        <a href="https://tech.happylight.rw" target="_blank">HappyLight Tech</a
        >. We specialize in creating innovative solutions for modern airports.
      </p>

      <!-- Video Section -->
      <div class="video-container"></div>

      <!-- Image Gallery -->
      <div class="image-gallery">
        <img src="https://picsum.photos/300/200?random=1" alt="Image 1" />
        <img src="https://picsum.photos/300/200?random=2" alt="Image 2" />
        <img src="https://picsum.photos/300/200?random=3" alt="Image 3" />
        <img src="https://picsum.photos/300/200?random=4" alt="Image 4" />
        <img src="https://picsum.photos/300/200?random=5" alt="Image 5" />
        <img src="https://picsum.photos/300/200?random=6" alt="Image 6" />
        <img src="https://picsum.photos/300/200?random=7" alt="Image 7" />
        <img src="https://picsum.photos/300/200?random=8" alt="Image 8" />
        <img src="https://picsum.photos/300/200?random=9" alt="Image 9" />
        <img src="https://picsum.photos/300/200?random=10" alt="Image 10" />
      </div>

      <!-- Control Button -->
      <button
        class="control-button"
        onclick="window.location.href = '/control'"
      >
        Go to Control Panel
      </button>
    </div>
  </body>
</html>


)=====";