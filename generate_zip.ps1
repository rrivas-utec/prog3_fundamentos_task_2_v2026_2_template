[CmdletBinding()]
param()

$ErrorActionPreference = 'Stop'
$projectName = 'prog3_fundamentos_task_2_v2026_2'
$sourceFiles = @(
    'include/average.h',
    'src/average.cpp',
    'include/book_search.h',
    'src/book_search.cpp',
    'include/distance.h',
    'src/distance.cpp',
    'include/fraction_vector2.h',
    'src/fraction_vector2.cpp',
    'include/polynomial_matrix.h',
    'src/polynomial_matrix.cpp',
    'include/permission_gray_image.h',
    'src/permission_gray_image.cpp',
    'include/grade_filter.h',
    'src/grade_filter.cpp',
    'include/message_format.h',
    'src/message_format.cpp',
    'include/price_rule.h',
    'src/price_rule.cpp',
    'include/report_exporter.h',
    'src/report_exporter.cpp'
)
$projectRoot = Split-Path -Parent $PSCommandPath
$outputPath = Join-Path $projectRoot "$projectName.zip"

foreach ($sourceFile in $sourceFiles) {
    if (-not (Test-Path -LiteralPath (Join-Path $projectRoot $sourceFile) -PathType Leaf)) {
        throw "No se encontro el archivo requerido: $sourceFile"
    }
}
if (Test-Path -LiteralPath $outputPath) { Remove-Item -LiteralPath $outputPath -Force }
Compress-Archive -LiteralPath ($sourceFiles | ForEach-Object { Join-Path $projectRoot $_ }) -DestinationPath $outputPath
Write-Host "Archivo generado: $outputPath"
