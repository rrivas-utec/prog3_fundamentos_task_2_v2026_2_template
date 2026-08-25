#!/usr/bin/env bash

project_name='prog3_fundamentos_task_2_v2026_2'
source_code='
  include/average.h src/average.cpp
  include/book_search.h src/book_search.cpp
  include/distance.h src/distance.cpp
  include/fraction_vector2.h src/fraction_vector2.cpp
  include/polynomial_matrix.h src/polynomial_matrix.cpp
  include/permission_gray_image.h src/permission_gray_image.cpp
  include/grade_filter.h src/grade_filter.cpp
  include/message_format.h src/message_format.cpp
  include/price_rule.h src/price_rule.cpp
  include/report_exporter.h src/report_exporter.cpp
  '
cd .. || exit 1
rm -f ${project_name}.zip
zip -r -S ${project_name} ${source_code}
