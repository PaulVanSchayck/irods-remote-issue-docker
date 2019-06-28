FROM ubuntu:16.04

# Load build arguments from environment
ARG ENV_IRODS_VERSION
ARG ENV_IRODS_EXT_CLANG_VERSION
ARG ENV_IRODS_EXT_CLANG_RUNTIME_VERSION

# Install packages
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    apt-transport-https \
    wget \
    postgresql-client \
    python \
    nano \
    git

ENV IRODS_VERSION ${ENV_IRODS_VERSION}

# Install iRODS
RUN wget -qO - https://packages.irods.org/irods-signing-key.asc | apt-key add - \
    && echo "deb [arch=amd64] https://packages.irods.org/apt/ xenial main" | tee /etc/apt/sources.list.d/renci-irods.list \
    && apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    irods-server=${IRODS_VERSION} \
    irods-database-plugin-postgres=${IRODS_VERSION} \
    irods-icommands=${IRODS_VERSION}

# Helper scripts
RUN mkdir /opt/irods
ADD setup_responses /etc/irods/setup_responses
ADD setupdb.sh /opt/irods/setupdb.sh
ADD prepend_ruleset.py /opt/irods/prepend_ruleset.py
ADD ./bootstrap.sh /opt/irods/bootstrap.sh
RUN chmod a+x /opt/irods/*

# Finalize
EXPOSE 1248 1247
ENTRYPOINT [ "/opt/irods/bootstrap.sh" ]
