/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/* mateweather-prefs.h - Preference handling functions
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef __MATEWEATHER_PREFS_H_
#define __MATEWEATHER_PREFS_H_

#include <libgweather/gweather.h>
#include <gio/gio.h>

/* gsettings keys */
#define GSETTINGS_TEMP_UNIT     "temperature-unit"
#define GSETTINGS_SPEED_UNIT    "speed-unit"
#define GSETTINGS_PRESSURE_UNIT "pressure-unit"
#define GSETTINGS_DISTANCE_UNIT "distance-unit"

typedef struct _MateWeatherPrefs MateWeatherPrefs;

struct _MateWeatherPrefs {
    GWeatherLocation *location;
    gboolean show_notifications;
    gint update_interval;  /* in seconds */
    gboolean update_enabled;
    gboolean detailed;
    gboolean radar_enabled;
    gboolean use_custom_radar_url;
    gchar *radar;

    GWeatherTemperatureUnit temperature_unit;
    GWeatherSpeedUnit speed_unit;
    GWeatherPressureUnit pressure_unit;
    GWeatherDistanceUnit distance_unit;
};

void		mateweather_prefs_load			(MateWeatherPrefs *prefs,
                                             GSettings *settings);

const char *  mateweather_prefs_get_temp_display_name    (GWeatherTemperatureUnit temp);
const char *  mateweather_prefs_get_speed_display_name    (GWeatherSpeedUnit speed);
const char *  mateweather_prefs_get_pressure_display_name  (GWeatherPressureUnit pressure);
const char *  mateweather_prefs_get_distance_display_name  (GWeatherDistanceUnit distance);

#endif /* __MATEWEATHER_PREFS_H_ */
