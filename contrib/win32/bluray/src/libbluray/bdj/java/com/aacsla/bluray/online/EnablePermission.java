/*
 * This file is part of libbluray
 * Copyright (C) 2012  libbluray
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see
 * <http://www.gnu.org/licenses/>.
 */

package com.aacsla.bluray.online;

import org.videolan.Libbluray;
import org.videolan.Logger;

public class EnablePermission {
    public EnablePermission(int title_id) {
    }

    public boolean checkPermission() {
        // TODO
        logger.unimplemented("checkPermission");
        return false;
    }

    public byte[] getNonce() {
        byte nonce[] = Libbluray.getAacsData(Libbluray.AACS_DEVICE_NONCE);
        if (nonce == null) {
            Logger.getLogger(DeviceAttribute.class.getName()).warning("getNonce() failed");
        }
        return nonce;
    }

    public boolean isCacheable() {
        // TODO
        logger.unimplemented("isCacheable");
        return false;
    }

    public boolean setPermission(byte[] message) throws NullPointerException {
        if (message == null)
            throw new NullPointerException();
        // TODO
        logger.unimplemented("setPermission");
        return false;
    }

    private static final Logger logger = Logger.getLogger(EnablePermission.class.getName());
}
