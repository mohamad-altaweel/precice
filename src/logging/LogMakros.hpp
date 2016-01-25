#pragma once

//#include "../utils/MasterSlave.hpp"

#define BOOST_LOG_DYN_LINK 1
#include <boost/log/expressions.hpp>
#include <boost/log/attributes/mutable_constant.hpp>

#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>

//#define assertion assertion

  
#define pprecicePrint(message) do                                            \
  {                                                                          \
    ppreciceInfo("unknown",message);                                         \
  } while (false)


#define ppreciceDebug(message) do                                           \
  {                                                                         \
    LOG_LOCATION;                                                           \
    BOOST_LOG_SEV(_log, boost::log::trivial::severity_level::debug)         \
    << message;                                                             \
  } while (false)

    
#define ppreciceWarning(methodname, message) do                             \
  {                                                                         \
    LOG_LOCATION;                                                           \
    BOOST_LOG_SEV(_log, boost::log::trivial::severity_level::warning)       \
    << message;                                                             \
  } while (false)
    
#define ppreciceInfo(methodname, message) do                                \
  {                                                                         \
    LOG_LOCATION;                                                           \
    BOOST_LOG_SEV(_log, boost::log::trivial::severity_level::info)          \
    << message;                                                             \
  } while (false)

/**
 * @brief Standard logging device used in macro preciceDebug.
 */
#define PRECICE_LOGGING_DEVICE _log

#ifdef Debug

#include "Tracer.hpp"

#define ppreciceTrace(methodname) do                                        \
  {                                                                         \
    LOG_LOCATION;                                                           \
    BOOST_LOG_FUNCTION();                                                   \
    precice::logging::Tracer _tracer_(_log, __func__, __FILE__,__LINE__);   \
    BOOST_LOG_SEV(_log, boost::log::trivial::severity_level::trace)         \
    << "Entering " << __func__;                                             \
  } while (false)

#define ppreciceTrace1(methodname, var1) do                                 \
  {                                                                         \
    LOG_LOCATION;                                                           \
    BOOST_LOG_FUNCTION();                                                   \
    precice::logging::Tracer _tracer_(_log, __func__, __FILE__,__LINE__);   \
    BOOST_LOG_SEV(_log, boost::log::trivial::severity_level::trace)         \
    << "Entering " << __func__                                              \
    << "\n" << #var1 << " = " << var1;                                      \
  } while (false)

#define ppreciceTrace2(methodname, var1, var2) do                           \
  {                                                                         \
    LOG_LOCATION;                                                           \
    BOOST_LOG_FUNCTION();                                                   \
    precice::logging::Tracer _tracer_(_log, __func__, __FILE__,__LINE__);   \
    BOOST_LOG_SEV(_log, boost::log::trivial::severity_level::trace)         \
    << "Entering " << __func__                                              \
    << "\n" << #var1 << " = " << var1                                       \
    << "\n" << #var2 << " = " << var2;                                      \
  } while (false)
 
#define ppreciceTrace3(methodname, var1, var2, var3) do                     \
  {                                                                         \
    LOG_LOCATION;                                                           \
    BOOST_LOG_FUNCTION();                                                   \
    precice::logging::Tracer _tracer_(_log, __func__, __FILE__,__LINE__);   \
    BOOST_LOG_SEV(_log, boost::log::trivial::severity_level::trace)         \
    << "Entering " << __func__                                              \
    << "\n" << #var1 << " = " << var1                                       \
    << "\n" << #var2 << " = " << var2                                       \
    << "\n" << #var3 << " = " << var3;                                      \
  } while (false)

#define ppreciceTrace4(methodname, var1, var2, var3, var4) do               \
  {                                                                         \
    LOG_LOCATION;                                                           \
    BOOST_LOG_FUNCTION();                                                   \
    precice::logging::Tracer _tracer_(_log, __func__, __FILE__,__LINE__);   \
    BOOST_LOG_SEV(_log, boost::log::trivial::severity_level::trace)         \
    << "Entering " << __func__                                              \
    << "\n" << #var1 << " = " << var1                                       \
    << "\n" << #var2 << " = " << var2                                       \
    << "\n" << #var3 << " = " << var3                                       \
    << "\n" << #var4 << " = " << var4;                                      \
  } while (false)
  
#define ppreciceTrace5(methodname, var1, var2, var3, var4, var5) do         \
  {                                                                         \
    LOG_LOCATION;                                                           \
    BOOST_LOG_FUNCTION();                                                   \
    precice::logging::Tracer _tracer_(_log, __func__, __FILE__,__LINE__);   \
    BOOST_LOG_SEV(_log, boost::log::trivial::severity_level::trace)         \
    << "Entering " << __func__                                              \
    << "\n" << #var1 << " = " << var1                                       \
    << "\n" << #var2 << " = " << var2                                       \
    << "\n" << #var3 << " = " << var3                                       \
    << "\n" << #var4 << " = " << var4                                       \
    << "\n" << #var5 << " = " << var5;                                      \
  } while (false)
  
#define ppreciceTrace6(methodname, var1, var2, var3, var4, var5, var6) do   \
  {                                                                         \
    LOG_LOCATION;                                                           \
    BOOST_LOG_FUNCTION();                                                   \
    precice::logging::Tracer _tracer_(_log, __func__, __FILE__,__LINE__);   \
    BOOST_LOG_SEV(_log, boost::log::trivial::severity_level::trace)         \
    << "Entering " << __func__                                              \
    << "\n" << #var1 << " = " << var1                                       \
    << "\n" << #var2 << " = " << var2                                       \
    << "\n" << #var3 << " = " << var3                                       \
    << "\n" << #var4 << " = " << var4                                       \
    << "\n" << #var5 << " = " << var5                                       \
    << "\n" << #var6 << " = " << var6;                                      \
  } while (false)
  
#else // Debug

//#define preciceDebug(methodname, message)
#define ppreciceTrace(methodname)
#define ppreciceTrace1(methodname, var1)
#define ppreciceTrace2(methodname, var1, var2)
#define ppreciceTrace3(methodname, var1, var2, var3)
#define ppreciceTrace4(methodname, var1, var2, var3, var4)
#define ppreciceTrace5(methodname, var1, var2, var3, var4, var5)
#define ppreciceTrace6(methodname, var1, var2, var3, var4, var5, var6)

#endif // ! Debug

/**
 * @brief Needed for macros exiting program execution, to empty logging cache.
 */
//#ifdef _UTILS_LOG_H_
//#define PRECICE_CLOSE_LOGGER precice::logging::Log::criticalAbort();
//#else
//#define PRECICE_CLOSE_LOGGER
//#endif


   
#define ppreciceError(methodname, message) do                             \
  {                                                                       \
    LOG_LOCATION;                                                         \
    BOOST_LOG_SEV(_log, boost::log::trivial::severity_level::error)       \
    << message                                                            \
    std::abort();                                                         \
  } while (false)

#define ppreciceCheck(check, methodname, errormessage)                    \
  if ( !(check) ) {                                                       \
    ppreciceError(methodname, errormessage);                              \
  }

  
#define LOG_LOCATION do                                                                 \
  {                                                                                     \
    boost::log::attribute_cast<boost::log::attributes::mutable_constant<int>>(          \
      boost::log::core::get()->get_global_attributes()["Line"]).set(__LINE__);          \
    boost::log::attribute_cast<boost::log::attributes::mutable_constant<std::string>>(  \
      boost::log::core::get()->get_global_attributes()["File"]).set(__FILE__);          \
    boost::log::attribute_cast<boost::log::attributes::mutable_constant<std::string>>(  \
      boost::log::core::get()->get_global_attributes()["Function"]).set(__func__);      \
  } while (false)

  






