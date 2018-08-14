#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

cat ${DIR}/include/Logger.hpp | grep -v '#include "' > ${DIR}/output.cpp
cat ${DIR}/include/CardDeck.hpp | grep -v '#include "' >> ${DIR}/output.cpp
cat ${DIR}/include/Player.hpp | grep -v '#include "' >> ${DIR}/output.cpp
cat ${DIR}/include/Decision.hpp | grep -v '#include "' >> ${DIR}/output.cpp
cat ${DIR}/include/GameController.hpp | grep -v '#include "' >> ${DIR}/output.cpp

cat ${DIR}/src/Logger.cpp | grep -v '#include "' >> ${DIR}/output.cpp
cat ${DIR}/src/CardDeck.cpp | grep -v '#include "' >> ${DIR}/output.cpp
cat ${DIR}/src/Player.cpp | grep -v '#include "' >> ${DIR}/output.cpp
cat ${DIR}/src/Decision.cpp | grep -v '#include "' >> ${DIR}/output.cpp
cat ${DIR}/src/GameController.cpp | grep -v '#include "' >> ${DIR}/output.cpp
cat ${DIR}/src/main.cpp | grep -v '#include "' >> ${DIR}/output.cpp
