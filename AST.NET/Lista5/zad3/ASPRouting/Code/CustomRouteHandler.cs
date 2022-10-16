﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Routing;

namespace ASPRouting.Code
{
    public class CustomRouteHandler : IRouteHandler
    {
        #region IRouteHandler Members

        public IHttpHandler GetHttpHandler( RequestContext requestContext )
        {
            return new CustomHttpHandler();
        }

        #endregion
    }
}