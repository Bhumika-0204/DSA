/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if (typeof classFunction !== "function") return false;
    if (obj === null || obj === undefined) return false;
    if (typeof obj !== "object") {
        return Object(obj) instanceof classFunction;
    }

    let proto = Object.getPrototypeOf(obj);

    while (proto !== null) {
        if (proto === classFunction.prototype) {
            return true;
        }
        proto = Object.getPrototypeOf(proto);
    }

    return false;
};


/**
 * checkIfInstanceOf(new Date(), Date); // true
 */