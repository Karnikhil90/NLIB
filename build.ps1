param (
    [string]$Run = ""
)

# --- Configuration ---
$CC = "gcc"
$CFLAGS = "-Wall", "-Wextra", "-g"
$INCLUDE = "-Iinclude"
$BUILD_DIR = "build"
$SRC_DIR = "src"
$EXAMPLES_DIR = "examples"

# 1. Create Build Directory
if (!(Test-Path $BUILD_DIR)) {
    New-Item -ItemType Directory -Path $BUILD_DIR | Out-Null
}

# 2. Compile Library Sources
$LibObjects = @()
$SrcFiles = Get-ChildItem -Path "$SRC_DIR/*.c"

foreach ($File in $SrcFiles) {
    $ObjFile = Join-Path $BUILD_DIR ($File.BaseName + ".o")
    $LibObjects += $ObjFile
    & $CC $CFLAGS $INCLUDE -c $File.FullName -o $ObjFile
}

# 3. Archive into Static Library
$LibPath = Join-Path $BUILD_DIR "libnlib.a"
& ar rcs $LibPath $LibObjects

# 4. Compile Examples
$Examples = Get-ChildItem -Path "$EXAMPLES_DIR/*.c"
foreach ($Example in $Examples) {
    $ExeName = Join-Path $BUILD_DIR ($Example.BaseName + ".exe")
    & $CC $CFLAGS $INCLUDE $Example.FullName $LibPath -o $ExeName
}

# --- 5. Run Logic (The "Makefile" replacement) ---
if ($Run -ne "") {
    $TargetExe = Join-Path $BUILD_DIR ($Run + ".exe")
    
    if (Test-Path $TargetExe) {
        Write-Host "`n--- Running $Run ---" -ForegroundColor Yellow
        & $TargetExe
    } else {
        Write-Host "Error: Target '$Run' not found in build folder." -ForegroundColor Red
    }
} else {
    Write-Host "Build Successful! (No run target specified)" -ForegroundColor Green
}