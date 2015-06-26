# - Find FFTW
# Find the native FFTW includes and library
#
#  FFTW_INCLUDES    - where to find fftw3.h
#  FFTW_LIBRARIES   - List of libraries when using FFTW.
#  FFTW_FOUND       - True if FFTW found.
if (FFTW_INCLUDES)
  # Already in cache, be silent
  set (FFTW_FIND_QUIETLY TRUE)
endif (FFTW_INCLUDES)

find_path (FFTW_INCLUDES fftw3.h)
find_library (FFTW_LIBRARY NAMES fftw3)
find_library (FFTW_OMP_LIBRARY NAMES fftw3_omp)
find_library (FFTWF_LIBRARY NAMES fftw3f)
find_library (CUFFT_LIBRARY NAMES cufft HINTS /opt/cuda/lib64)
set(FFTW_LIBRARIES ${FFTW_LIBRARY};${FFTWF_LIBRARY};${FFTW_OMP_LIBRARY};${CUFFT_LIBRARY})

# handle the QUIETLY and REQUIRED arguments and set FFTW_FOUND to TRUE if
# all listed variables are TRUE
include (FindPackageHandleStandardArgs)
find_package_handle_standard_args (FFTW DEFAULT_MSG FFTW_LIBRARY FFTWF_LIBRARY CUFFT_LIBRARY FFTW_INCLUDES)

mark_as_advanced (FFTW_LIBRARIES FFTW_INCLUDES)
