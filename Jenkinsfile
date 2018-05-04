pipeline {
    agent {
        docker {
            image 'gcc'
        }
    }
    stages {
        stage('Build') {
            steps {
                sh 'make -C ./hw1/Triangle'
                sh 'make -C ./hw1/NextDate'
                sh 'make -C ./hw1/CommissionProblem'
            }
        }
        stage('Test') {
            steps {
                sh 'make -C ./hw1/Triangle triangle_unittest'
                sh 'make -C ./hw1/NextDate next_date_unittest'
                sh 'make -C ./hw1/CommissionProblem commission_unittest'
            }
        }
    }
}