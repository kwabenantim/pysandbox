#ifndef _TYPECASTERS_HPP_
#define _TYPECASTERS_HPP_

#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <boost/numeric/ublas/vector.hpp>
#include <boost/shared_ptr.hpp>

#include <vector>

PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

#define PYBIND11_CVECTOR_TYPECASTER(T, N)                                                     \
  namespace pybind11                                                                          \
  {                                                                                           \
    namespace detail                                                                          \
    {                                                                                         \
      template <>                                                                             \
      struct type_caster<boost::numeric::ublas::c_vector<T, N>>                               \
      {                                                                                       \
      public:                                                                                 \
        typedef boost::numeric::ublas::c_vector<T, N> c_vector_##T##_##N##_t;                 \
        PYBIND11_TYPE_CASTER(c_vector_##T##_##N##_t, const_name("c_vector_" #T "_" #N "_t")); \
        bool load(handle src, bool convert)                                                   \
        {                                                                                     \
          if (!convert && !array_t<T>::check_(src))                                           \
          {                                                                                   \
            return false;                                                                     \
          }                                                                                   \
          auto buf = array_t<T, array::c_style | array::forcecast>::ensure(src);              \
          if (!buf)                                                                           \
          {                                                                                   \
            return false;                                                                     \
          }                                                                                   \
          if (buf.ndim() != 1 or buf.shape()[0] != N)                                         \
          {                                                                                   \
            return false;                                                                     \
          }                                                                                   \
          value.resize(N);                                                                    \
          for (int i = 0; i < N; i++)                                                         \
          {                                                                                   \
            value[i] = buf.data()[i];                                                         \
          }                                                                                   \
          return true;                                                                        \
        }                                                                                     \
        static handle cast(const boost::numeric::ublas::c_vector<T, N> &src,                  \
                           return_value_policy policy,                                        \
                           handle parent)                                                     \
        {                                                                                     \
          std::vector<size_t> shape(1, N);                                                    \
          std::vector<size_t> strides(1, sizeof(T));                                          \
          T *data = src.size() ? const_cast<T *>(&src[0]) : static_cast<T *>(NULL);           \
          array a(std::move(shape), std::move(strides), data);                                \
          return a.release();                                                                 \
        }                                                                                     \
      };                                                                                      \
    }                                                                                         \
  }

PYBIND11_CVECTOR_TYPECASTER(double, 2);
PYBIND11_CVECTOR_TYPECASTER(double, 3);

#endif //_TYPECASTERS_HPP_
