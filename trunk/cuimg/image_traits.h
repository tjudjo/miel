#ifndef CUIMG_IMAGE_TRAITS_H_
# define CUIMG_IMAGE_TRAITS_H_

# include <cuda_runtime.h>

# define BOOST_TYPEOF_COMPLIANT
# include <boost/typeof/typeof.hpp>
# include <boost/type_traits/remove_reference.hpp>
# include <boost/type_traits/remove_const.hpp>

namespace cuimg
{

  template <typename I, typename NV>
  struct change_value_type
  {
  };

  template <typename V, typename NV>
  struct change_value_type<host_image2d<V>, NV>
  {
    typedef host_image2d<NV> ret;
  };

  template <typename V, template <class> class PT, typename NV>
  struct change_value_type<image2d<V, PT>, NV>
  {
    typedef image2d<NV, PT> ret;
  };

}

#endif
