import i18n from "i18next";
import { initReactI18next } from "react-i18next";
import { languagesResources } from "./languages";

i18n.use(initReactI18next).init({
    compatibilityJSON: "v3",
    resources: languagesResources,
    lng: "en", //* Default language
    fallbackLng: "en", //* Fallback language
    interpolation: {
        escapeValue: false
    }
})

export default i18n;