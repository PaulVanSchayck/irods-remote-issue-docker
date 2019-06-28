FROM ubuntu:16.04

# Load build arguments from environment
ARG ENV_IRODS_VERSION

# Install packages
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    apt-transport-https \
    wget \
    curl \
    postgresql-client \
    python \
    nano \
    git

ENV IRODS_VERSION ${ENV_IRODS_VERSION}
ENV ENV_DOCKERIZE_VERSION ${ENV_DOCKERIZE_VERSION}

# Install iRODS
RUN wget -qO - https://packages.irods.org/irods-signing-key.asc | apt-key add - \
    && echo "deb [arch=amd64] https://packages.irods.org/apt/ xenial main" | tee /etc/apt/sources.list.d/renci-irods.list \
    && apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    irods-server=${IRODS_VERSION} \
    irods-database-plugin-postgres=${IRODS_VERSION} \
    irods-runtime=${IRODS_VERSION} \
    irods-icommands=${IRODS_VERSION}

# Use Dockerize
RUN curl -fSL https://github.com/jwilder/dockerize/releases/download/v0.6.1/dockerize-linux-amd64-v0.6.1.tar.gz \
        -o dockerize.tar.gz \
    && tar -C /usr/local/bin -xzvf dockerize.tar.gz

CMD dockerize -wait tcp://irods:1247 -timeout 200s /opt/irods/bootstrap.sh

# Helper scripts
RUN mkdir /opt/irods
ADD setup_responses /etc/irods/setup_responses
ADD setupdb.sh /opt/irods/setupdb.sh
ADD ./bootstrap.sh /opt/irods/bootstrap.sh
RUN chmod a+x /opt/irods/*

