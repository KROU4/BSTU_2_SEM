import React, { useState } from 'react';

const jobs = [
  { id: 1, name: 'Веб-разработчик', menuItems: ['HTML', 'CSS', 'JavaScript', 'React', 'Node.js', 'MongoDB', 'Git'] },
  { id: 2, name: 'UI/UX дизайнер', menuItems: ['Wireframing', 'Sketch', 'Adobe XD', 'InVision', 'User testing', 'Visual design', 'Typography'] },
  { id: 3, name: 'Аналитик данных', menuItems: ['SQL', 'Python', 'Data visualization', 'Statistics', 'Machine learning', 'Excel', 'Tableau'] },
  { id: 4, name: 'Специалист по маркетингу', menuItems: ['Social media', 'SEO', 'Content creation', 'Email marketing', 'Analytics', 'Campaign planning', 'Brand strategy'] },
  { id: 5, name: 'Руководитель проекта', menuItems: ['Agile methodology', 'Project planning', 'Team management', 'Risk management', 'Communication', 'Budgeting', 'Time management'] },
];

const JobMenu = () => {
  const [selectedJob, setSelectedJob] = useState(jobs[0]);

  const handleJobChange = (event) => {
    const selectedJobId = Number(event.target.value);
    const selectedJob = jobs.find((job) => job.id === selectedJobId);
    setSelectedJob(selectedJob);
  };

  return (
    <div>
      <h2>Выбрать работу:</h2>
      <select onChange={handleJobChange}>
        {jobs.map((job) => (
          <option key={job.id} value={job.id}>
            {job.name}
          </option>
        ))}
      </select>
      <h2>{selectedJob.name} навыки:</h2>
      <ul>
        {selectedJob.menuItems.map((menuItem) => (
          <li key={menuItem}>{menuItem}</li>
        ))}
      </ul>
    </div>
  );
};

export default JobMenu;