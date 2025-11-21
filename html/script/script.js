const cameraFeed = document.getElementById("cameraFeed");

navigator.mediaDevices
  .getUserMedia({ vide0: true })

  .then((stream) => {
    cameraFeed.srcObject = stream;
  });
