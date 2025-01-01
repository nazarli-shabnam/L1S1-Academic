const LOCAL_STORAGE_KEY = "drivingExperiences";

function fetchLocalData() {
  const data = localStorage.getItem(LOCAL_STORAGE_KEY);
  return data ? JSON.parse(data) : [];
}

function saveLocalData(data) {
  localStorage.setItem(LOCAL_STORAGE_KEY, JSON.stringify(data));
}

async function populateData() {
  const data = {
    weather: [
      { id: "1", name: "Sunny" },
      { id: "2", name: "Rainy" },
      { id: "3", name: "Stormy" },
    ],
    roadType: [
      { id: "1", name: "Highway" },
      { id: "2", name: "City Road" },
      { id: "3", name: "Country Road" },
    ],
    traffic: [
      { id: "1", name: "Light" },
      { id: "2", name: "Moderate" },
      { id: "3", name: "Heavy" },
    ],
  };
  populateSelect("idWeather", data.weather);
  populateSelect("idRoadType", data.roadType);
  populateSelect("idTraffic", data.traffic);
}

function populateSelect(elementId, options) {
  const selectElement = document.getElementById(elementId);
  options.forEach((option) => {
    const newOption = document.createElement("option");
    newOption.value = option.id;
    newOption.textContent = option.name;
    selectElement.appendChild(newOption);
  });
}

function calculateTotalDistance() {
  const experiences = fetchLocalData();
  return experiences.reduce((total, exp) => total + exp.km, 0);
}

function getStatistics(key, mapping) {
  const experiences = fetchLocalData();
  return experiences.reduce((stats, exp) => {
    const keyValue = exp[key];
    const keyLabel = mapping[keyValue] || keyValue;
    stats[keyLabel] = (stats[keyLabel] || 0) + 1;
    return stats;
  }, {});
}

let barChartInstance = null;
let pieChartInstances = {};

function renderBarChart() {
  const ctx = document.getElementById("summaryChart").getContext("2d");
  const experiences = fetchLocalData();

  const weatherMapping = { 1: "Sunny", 2: "Rainy", 3: "Stormy" };
  const roadTypeMapping = { 1: "Highway", 2: "City Road", 3: "Country Road" };
  const trafficMapping = { 1: "Light", 2: "Moderate", 3: "Heavy" };

  const weatherStats = getStatistics("weather", weatherMapping);
  const roadTypeStats = getStatistics("roadType", roadTypeMapping);
  const trafficStats = getStatistics("traffic", trafficMapping);

  const data = {
    labels: Object.keys(weatherStats),
    datasets: [
      {
        label: "Weather Conditions",
        data: Object.values(weatherStats),
        backgroundColor: "#FF6384",
      },
      {
        label: "Road Types",
        data: Object.values(roadTypeStats),
        backgroundColor: "#36A2EB",
      },
      {
        label: "Traffic Conditions",
        data: Object.values(trafficStats),
        backgroundColor: "#FFCE56",
      },
    ],
  };

  if (barChartInstance) {
    barChartInstance.destroy();
  }

  barChartInstance = new Chart(ctx, {
    type: "bar",
    data,
    options: {
      responsive: true,
      plugins: {
        legend: {
          position: "top",
        },
        title: {
          display: true,
          text: "Detailed Summary of Driving Experiences (Bar Chart)",
        },
      },
      scales: {
        x: {
          stacked: true,
        },
        y: {
          stacked: true,
        },
      },
    },
  });
}

function renderPieCharts() {
  const chartConfigs = [
    {
      id: "pieChartWeather",
      key: "weather",
      mapping: { 1: "Sunny", 2: "Rainy", 3: "Stormy" },
      title: "Weather Distribution",
    },
    {
      id: "pieChartRoadType",
      key: "roadType",
      mapping: { 1: "Highway", 2: "City Road", 3: "Country Road" },
      title: "Road Type Distribution",
    },
    {
      id: "pieChartTraffic",
      key: "traffic",
      mapping: { 1: "Light", 2: "Moderate", 3: "Heavy" },
      title: "Traffic Distribution",
    },
  ];

  chartConfigs.forEach((config) => {
    const ctx = document.getElementById(config.id).getContext("2d");
    const stats = getStatistics(config.key, config.mapping);

    const data = {
      labels: Object.keys(stats),
      datasets: [
        {
          label: config.title,
          data: Object.values(stats),
          backgroundColor: ["#FF6384", "#36A2EB", "#FFCE56"],
        },
      ],
    };

    if (pieChartInstances[config.id]) {
      pieChartInstances[config.id].destroy();
    }

    pieChartInstances[config.id] = new Chart(ctx, {
      type: "pie",
      data,
      options: {
        responsive: true,
        plugins: {
          legend: {
            position: "top",
          },
          title: {
            display: true,
            text: config.title,
          },
        },
      },
    });
  });
}

document.getElementById("submitExperience").addEventListener("click", () => {
  const experiences = fetchLocalData();
  const lastIdentifier =
    experiences.length > 0 ? experiences[experiences.length - 1].identifier : 0;
  const identifier = lastIdentifier + 1;

  const date = document.getElementById("date").value;
  const startTime = document.getElementById("start_time").value;
  const endTime = document.getElementById("end_time").value;
  const km = parseInt(document.getElementById("km").value, 10);
  const weather = document.getElementById("idWeather").value;
  const roadType = document.getElementById("idRoadType").value;
  const traffic = document.getElementById("idTraffic").value;

  if (
    !date ||
    !startTime ||
    !endTime ||
    !km ||
    !weather ||
    !roadType ||
    !traffic
  ) {
    alert("Please fill out all fields.");
    return;
  }

  const newExperience = {
    identifier,
    date,
    startTime,
    endTime,
    km,
    weather,
    roadType,
    traffic,
  };

  experiences.push(newExperience);
  saveLocalData(experiences);

  alert(`Experience saved! Total Distance: ${calculateTotalDistance()} km.`);
  document.getElementById("drivingForm").reset();
  renderBarChart();
  renderPieCharts();
});

populateData();
renderBarChart();
renderPieCharts();
